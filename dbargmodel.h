#ifndef DBARGMODEL_H
#define DBARGMODEL_H

#include "sqltype.h"
#include <QString>
#include<QVariantList>
#include "dbcomtools_global.h"
class DBCOMTOOLSSHARED_EXPORT DBArgModel
{
public:
    DBArgModel();
    QString sql;
    SQLTYPE sqltype;
    QMap<QString,QVariantList> *args;
    QString sqls[];
};

#endif // DBARGMODEL_H
