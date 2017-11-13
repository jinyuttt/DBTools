#include "dbcomtools.h"

#include "dbresult.h"
#include "dbsql.h"
DBComTools::DBComTools()
{
}

QSqlDatabase DBComTools::getDB()
{
  return  ConnectionPool::openConnection();
}

void DBComTools::closeConnectDB(QSqlDatabase db)
{
    ConnectionPool::closeConnection(db);
}

void DBComTools::setDBInfo(QMap<QString, QString> map)
{
    ConnectionPool::map=map;
}

DBResult DBComTools::exeSql(DBArgModel sql, bool isjson)
{
    DBSql db;
   DBResult result= db.exeSql(sql);
    if(result.getCode()==sucess&&isjson)
    {
      result.setJsonTable(DataTableToJson::toJson(*result.getTable()));
      //释放
      delete result.getTable();
    }
    return result;

}

QString DBComTools::exeSelectJsonSql(DBArgModel sql)
{
   return   exeSql(sql,true).getJsonTable();
}

DBComTools *getDBComTools()
{
    return new DBComTools();
}

QSqlDatabase getDB()
{
      DBComTools tool;
      return  tool.getDB();
}

void closeConnectDB(QSqlDatabase db)
{
     DBComTools tool;
     tool.closeConnectDB(db);
}

void setDBInfo(QMap<QString, QString> map)
{
        DBComTools tool;
        tool.setDBInfo(map);
}

DBResult exeSql(DBArgModel sql, bool isjson)
{
     DBComTools tool;
   return   tool.exeSql(sql,isjson);
}
