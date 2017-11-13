#ifndef CONNECTIONPOOL_H
#define CONNECTIONPOOL_H

#include <QtSql>
#include <QQueue>
#include <QString>
#include <QMutex>
#include <QMutexLocker>
class ConnectionPool
{

public:
    static void release(); // 关闭所有的数据库连接
    static QSqlDatabase openConnection();                 // 获取数据库连接
    static void closeConnection(QSqlDatabase connection); // 释放数据库连接回连接池
    static void loadConfig();
    static QMap<QString,QString> map;
    static QString filepath;
     ~ConnectionPool();

private:

    ConnectionPool();
    ConnectionPool(const ConnectionPool &other);
    ConnectionPool& operator=(const ConnectionPool &other);
    QSqlDatabase createConnection(const QString &connectionName); // 创建数据库连接
    QQueue<QString> usedConnectionNames;   // 已使用的数据库连接名
    QQueue<QString> unusedConnectionNames; // 未使用的数据库连接名

    // 数据库信息
    QString hostName;
    QString databaseName;
    QString username;
    QString password;
    QString databaseType;
    int port=0;
    bool    testOnBorrow;    // 取得连接的时候验证连接是否有效
    QString testOnBorrowSql; // 测试访问数据库的 SQL

    int maxWaitTime=40;  // 获取连接最大等待时间
    int waitInterval=40; // 尝试获取连接时等待间隔时间
    int maxConnectionCount=10; // 最大连接
    static QMutex mutex;
    static QWaitCondition waitConnection;
    static ConnectionPool *m_pInstance;
    static ConnectionPool* getInstance();
};

#endif // CONNECTIONPOOL_H
