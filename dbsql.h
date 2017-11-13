#ifndef DBSQL_H
#define DBSQL_H
#include "datarow.h"
#include "datatable.h"
#include "datacloumn.h"
#include "dbargmodel.h"
#include "dbresult.h"
#include <QSqlQuery>
#include "dbcomtools_global.h"
 class DBCOMTOOLSSHARED_EXPORT DBSql
{
public:
    DBSql();
   DBResult  exeSql(DBArgModel sql);
private:
   DataTable* getDataTable(QSqlQuery query);
};

#endif // DBSQL_H
