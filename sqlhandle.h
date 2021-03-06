#ifndef SQLHANDLE_H
#define SQLHANDLE_H

#define IS_USE_QSTRING 1

#include <QWidget>
#include <QFile>
#include <QSettings>
#include <QVariant>
#include <QList>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

class SqlHandle: public QWidget{
    Q_OBJECT
public:
    SqlHandle(QWidget* parent = nullptr);
    ~SqlHandle();

    static bool ExecuteNonQuery(QString sql, QVariantList params);
#if IS_USE_QSTRING
    static QList<QString> ExcuteScalar(QString sql, QVariantList params);
    static QList<QList<QString>> ExcuteDataSet(QString sql, QVariantList params);
#else
    static QVariantList ExcuteScalar(QString sql, QVariantList params);
    static QList<QVariantList> ExcuteDataSet(QString sql, QVariantList params);
#endif
private:
    static QSettings* dbconfig;
    static QSqlDatabase db;
    static QSqlQuery* query;

    bool db_init();
    bool db_deinit();
};

#endif // SQLHANDLE_H
