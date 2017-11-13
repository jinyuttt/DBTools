#include "datatabletojson.h"
#include <QVariant>
#include <QDebug>

DataTableToJson::DataTableToJson()
{

}

QString DataTableToJson::toJson(DataTable dt)
{
    qDebug()<<"转换datatable";
    if(dt.rowNum==0&&dt.colNum==0)
    {
        return "";
    }
    QJsonObject jdt;
    QJsonArray jcol;
    QJsonObject dcol;
    QJsonArray jrow;
     qDebug()<<"执行转换datatable";
   //列
    QList<DataCloumn>::iterator i;
   for (i = dt.col->begin(); i != dt.col->end(); ++i) {
        QJsonObject jcols=toJson(*i);
        jcol.push_back(jcols);
   }
    qDebug()<<"执行转列";
  //行
  QList<DataRow>::iterator j;
  for (j = dt.rowList->begin();j!= dt.rowList->end();++j) {

       QJsonObject jcols=toJson(*j);
       jrow.push_back(jcols);
  }
  qDebug()<<"执行转行";
  // 数据
  jdt.insert("index",dt.index);
  jdt.insert("rowNum",dt.rowNum);
  jdt.insert("colNum",dt.colNum);
  //
  jdt.insert("col",jcol);
  jdt.insert("rowList",jrow);
  return QString(QJsonDocument(jdt).toJson());
}

QJsonObject DataTableToJson::toJson(const DataRow &row)
{
    QJsonObject jrow;

    jrow.insert("rowNo",row.rowNo);
     QJsonArray array=QJsonArray::fromStringList(row.data);
    jrow.insert("data",array);
    // QJsonArray datas=QJsonArray::fromVariantList(row.data);
    // jrow.insert("data",datas);
    return jrow;
}

QJsonObject DataTableToJson::toJson(const DataCloumn &col)
{
    QJsonObject jcol;
    jcol.insert("cloumnType",col.cloumnType);
    jcol.insert("length",col.length);
    jcol.insert("name",col.name);
    return jcol;
}
