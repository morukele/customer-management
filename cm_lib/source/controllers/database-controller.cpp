#include "database-controller.h"

#include <QSqlDatabase>
#include <QSqlQuery>

namespace cm {
namespace controllers {

    class DatabaseController::Implementation
    {
    public:
        Implementation(DatabaseController* _databaseController)
            : databaseController(_databaseController)
        {
            if (initialise()) {
                qDebug() << "Database created using Sqlite version: " + sqliteVersion();
                if (createTables()) {
                    qDebug() << "Database tables created";
                } else {
                    qDebug() << "ERROR: Unable to create database tables";
                }
            } else {
                qDebug() << "ERROR: Unable to open database";
            }
        }

        DatabaseController* databaseController{nullptr};
        QSqlDatabase database;

    private:
        bool initialise()
        {
            database = QSqlDatabase::addDatabase("QSALITE", "cm");
            database.setDatabaseName("cm.sqlite");
            return database.open();
        }

        bool createTables()
        {
            return createJsonTable("client");
        }

        bool createJsonTable(const QString& tableName) const
        {
            QSqlQuery query(database);
            QString sqlStatement = "CREATE TABLE IF NOT EXISTS " + tableName + " (id text primary key, json text not null)";

            if (!query.prepare(sqlStatement)) return false;

            return query.exec();

        }

        QString sqliteVersion() const
        {
            QSqlQuery query(database);

            query.exec("SELECT sqlite_version()");

            if (query.next()) return query.value(0).toString();

            return QString::number(-1);
        }
    };

    bool DatabaseController::createRow(const QString& tableName, const QString& id, const QJsonObject& jsonObject) const
    {
        if (tableName.isEmpty()) return false;
        if (id.isEmpty()) return false;
        if (jsonObject.isEmpty()) return false;

        QSqlQuery query(implementation->database);

        QString sqlStatement = "INSERT OR REPLACE INTO " + tableName + "(id, json) VALUES (:id, :json)";

        if(!query.prepare(sqlStatement)) return false;

        query.bindValue(":id", QVariant(id));
        query.bindValue(":json", QVariant(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact)));

        if (!query.exec()) return false;

        return query.numRowsAffected() > 0;
    }
}}
