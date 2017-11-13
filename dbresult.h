#ifndef DBRESULT_H
#define DBRESULT_H

#include "datatable.h"
#include "dbcomtools_global.h"
enum ReturnCode{sucess,fail,SQL_ERROR};
class DBCOMTOOLSSHARED_EXPORT DBResult
{
public:
    DBResult();
    QString getError();
    QString getJsonTable();
    DataTable* getTable();
    ReturnCode getCode();
    int getResultNum();
    void setError(QString msg);
    void setTable(DataTable *dt);
    void setCode(ReturnCode code);
    void setRowNum(int num);
    void setJsonTable(QString json);
private :
    QString msgError;
    QString jsonTable;
    ReturnCode returncode=sucess;
    DataTable* datatable;
    int rowNum=-1;
};

#endif // DBRESULT_H
