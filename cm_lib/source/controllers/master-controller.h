#ifndef MASTER_CONTROLLER_H
#define MASTER_CONTROLLER_H

#include <QObject>
#include <QString>
#include <QScopedPointer>

#include <cm_lib_global.h>
#include <controllers/navigation-controller.h>
#include <controllers/command-controller.h>
#include <controllers/database-controller.h>
#include <models/client-search.h>
#include <models/client.h>

namespace cm {
namespace controllers {

    class CM_LIB_EXPORT MasterController : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString ui_welcomeMessage READ welcomeMessage CONSTANT)
        Q_PROPERTY(cm::controllers::NavigationController* ui_navigationController READ navigationController CONSTANT)
        Q_PROPERTY(cm::controllers::CommandController* ui_commandController READ commandController CONSTANT)
        Q_PROPERTY(cm::controllers::DatabaseController* ui_databaseController READ databaseController CONSTANT)
        Q_PROPERTY(cm::models::ClientSearch* ui_clientSearch READ clientSearch CONSTANT)
        Q_PROPERTY(cm::models::Client* ui_newClient READ newClient CONSTANT)

    public:
        explicit MasterController(QObject *parent = nullptr);
        ~MasterController();

        CommandController* commandController();
        DatabaseController* databaseController();
        NavigationController* navigationController();
        models::Client* newClient();
        models::ClientSearch* clientSearch();
        const QString& welcomeMessage() const;

    public slots:
        void selectClient(cm::models::Client* client);
        void onRssReplyReceived(int statusCode, QByteArray body);

    private:
        class Implementation;
        QScopedPointer<Implementation> implementation;
    };
}}

#endif // MASTER_CONTROLLER_H
