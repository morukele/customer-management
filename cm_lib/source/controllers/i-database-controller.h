#ifndef I_DATABASE_CONTROLLER_H
#define I_DATABASE_CONTROLLER_H

#include <QJsonArray>
#include <QJsonObject>
#include <QList>
#include <QObject>
#include <QString>

#include <cm_lib_global.h>

namespace cm {
namespace controllers {

    class CM_LIB_EXPORT IDatabaseController : public QObject
    {
        Q_OBJECT
    public:
        IDatabaseController(QObject* parent) : QObject(parent) {}
        virtual ~IDatabaseController() {}

        virtual bool createRow(const QString& tableName, const QString& id, const QJsonObject& jsonObject) const = 0;
        virtual bool deleteRow(const QString& tableName, const QString& id) const = 0;
        virtual QJsonArray find(const QString& tableName, const QString& searchText) const = 0;
        virtual QJsonObject readRow(const QString& tableName, const QString& id) const = 0;
        virtual bool updateRow(const QString& tableName, const QString& id, const QJsonObject& jsonObject) const = 0;
    };
}}

#endif // I_DATABASE_CONTROLLER_H
