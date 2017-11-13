#include "dbresult.h"

DBResult::DBResult()
{

}

QString DBResult::getError()
{
    return msgError;
}

QString DBResult::getJsonTable()
{
   return jsonTable;
}

DataTable* DBResult::getTable()
{
   return datatable;
}

ReturnCode DBResult::getCode()
{
    return returncode;
}

int DBResult::getResultNum()
{

}

void DBResult::setError(QString msg)
{
    msgError=msg;
}

void DBResult::setTable(DataTable *dt)
{
    datatable=dt;
}

void DBResult::setCode(ReturnCode code)
{
    returncode=code;
}

void DBResult::setRowNum(int num)
{
    rowNum=num;
}

void DBResult::setJsonTable(QString json)
{
  jsonTable=json;
}
