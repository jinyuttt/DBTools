#ifndef DBCOMTOOLS_H
#define DBCOMTOOLS_H

#include "dbcomtools_global.h"
#include "connectionpool.h"
#include "dbsql.h"
#include "dbresult.h"
#include "datatabletojson.h"
class DBCOMTOOLSSHARED_EXPORT DBComTools
{

    //共享库
public:
    DBComTools();
     QSqlDatabase getDB();
     void closeConnectDB(QSqlDatabase db);
      void setDBInfo(QMap<QString,QString> map);
      DBResult exeSql(DBArgModel sql,bool isjson);
      QString exeSelectJsonSql(DBArgModel sql);

};
extern "C" {
    DBCOMTOOLSSHARED_EXPORT DBComTools* getDBComTools(); //获取类SharedLibrary对象
    DBCOMTOOLSSHARED_EXPORT QSqlDatabase getDB();  //自定义的外部函数
   DBCOMTOOLSSHARED_EXPORT void closeConnectDB(QSqlDatabase db);  //自定义的外部函数
   DBCOMTOOLSSHARED_EXPORT void setDBInfo(QMap<QString,QString> map);  //自定义的外部函数
   DBCOMTOOLSSHARED_EXPORT  DBResult exeSql(DBArgModel sql,bool isjson);  //自定义的外部函数
}
#endif // DBCOMTOOLS_H
