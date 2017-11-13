#include "dbsql.h"
#include <QSqlRecord>

#include <QSqlField>
#include "connectionpool.h"
#include "dbresult.h"
DBSql::DBSql()
{

}
DBResult  DBSql::exeSql(DBArgModel sql)
{
    QSqlDatabase db=ConnectionPool::openConnection();
    QSqlQuery query(db);
    DBResult *result=new DBResult();
    result->setCode(sucess);
     if(sql.sqltype==Select)
     {
         //一般查询
       bool r= query.exec(sql.sql);
       if(r)
       {
           if(db.driver()->hasFeature(QSqlDriver::QuerySize))
           {
                 result->setRowNum(query.size());
           }
           query.setForwardOnly(true);
           DataTable *tb= getDataTable(query);
           result->setTable(tb);

       }
       else
       {
            result->setCode(SQL_ERROR);
            result->setError( query.lastError().text());
       }
     }
     else if(sql.sqltype==SelectArg)
     {
        query.prepare(sql.sql);
        QMap<QString,QVariantList>::const_iterator it=sql.args->constBegin();
        while(it!=sql.args->constEnd())
        {
           query.bindValue(it.key(),it.value());
        }
        //
        if(query.exec())
        {
            if(db.driver()->hasFeature(QSqlDriver::QuerySize))
            {
                  result->setRowNum(query.size());
            }
            query.setForwardOnly(true);
            DataTable *tb= getDataTable(query);
            result->setTable(tb);
        }
        else
        {
            result->setCode(SQL_ERROR);
            result->setError( query.lastError().text());
        }

     }
     else if(sql.sqltype==ExeSql)
     {
         if(query.exec(sql.sql))
         {
              result->setRowNum(query.numRowsAffected());
         }
         else
         {
             result->setCode(SQL_ERROR);
             result->setError( query.lastError().text());
         }

     }
     else if(sql.sql==ExeSqlArg)
     {
          query.prepare(sql.sql);
          QMap<QString,QVariantList>::const_iterator it=sql.args->constBegin();
          while(it!=sql.args->constEnd())
          {
             query.bindValue(it.key(),it.value());
          }
          if(query.execBatch())
          {
              result->setRowNum(query.numRowsAffected());
          }
          else
          {
              result->setCode(SQL_ERROR);
              result->setError( query.lastError().text());
          }
     }
     else if(sql.sqltype==transaction)
     {
         //一条语句执行的都不开启事务
          db.transaction();
          int num=sizeof(sql.sqls) / sizeof(sql.sqls[0]);
          //多条语句才会使用事务
          for(int i=0;i<num;i++)
          {
               QSqlQuery querytmp(sql.sqls[i], db);
               querytmp.exec();
          }
       bool r=   db.commit();
        result->setRowNum(query.numRowsAffected());
       if(!r)
       {
           result->setCode(SQL_ERROR);
           result->setError( query.lastError().text());
           db.rollback();
       }

     }
     //
     ConnectionPool::closeConnection(db);
     return *result;
}

DataTable *DBSql::getDataTable(QSqlQuery query)
{
    bool r= query.first();
    if(!r)
    {
        return NULL;
    }
    int colNum= query.record().count();
    //DataCloumn* cols=new DataCloumn[colNum];
    DataTable *tb=new DataTable();
    tb->rowList=new QList<DataRow>();
    tb->col=new QList<DataCloumn>();
    tb->colNum=colNum;

    //初始化
    for(int i=0;i<colNum;i++)
    {
        DataCloumn col;
        col.cloumnType=query.value(i).typeName();
        col.length=query.record().field(i).length();
        col.name=query.record().fieldName(i);
       // cols[i]=col;
         tb->col->append(col);
    }

    //首行
    DataRow row;
    for(int i=0;i<colNum;i++)
    {
          //cols[i].cloumnData.append(query.value(0).toString());
         row.data.append(query.value(i).toString());
    }
    tb->rowList->append(row);
    //
    while(query.next())
    {
        DataRow row;
        for(int i=0;i<colNum;i++)
        {
              //cols[i].cloumnData.append(query.value(0).toString());
             row.data.append(query.value(i).toString());
        }
        tb->rowList->append(row);
    }
    tb->rowNum=tb->rowList->size();
    return tb;
}
