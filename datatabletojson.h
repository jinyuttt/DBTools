#ifndef DATATABLETOJSON_H
#define DATATABLETOJSON_H
#include "datatable.h"
#include "datacloumn.h"
#include "datarow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include<QJsonValue>
#include <QJsonArray>
class DataTableToJson
{
public:
    DataTableToJson();
    static  QString toJson(DataTable dt);
    static  QJsonObject toJson(const DataRow &row);
    static  QJsonObject toJson(const DataCloumn &col);
};

#endif // DATATABLETOJSON_H
