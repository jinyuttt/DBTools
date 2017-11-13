#ifndef DATATABLE_H
#define DATATABLE_H

#include<QList>
#include "datarow.h"
#include "datacloumn.h"
#include "dbcomtools_global.h"
class DBCOMTOOLSSHARED_EXPORT DataTable
{
public:
    DataTable();\
    int index=0;
    QList<DataRow> *rowList;
    QList<DataCloumn> *col;
    int colNum=0;
    int rowNum=0;

};

#endif // DATATABLE_H
