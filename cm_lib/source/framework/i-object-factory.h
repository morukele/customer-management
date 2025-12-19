#ifndef I_OBJECT_FACTORY_H
#define I_OBJECT_FACTORY_H

#include <controllers/i-database-controller.h>
#include <models/client.h>
#include <models/client-search.h>
#include <networking/i-network-access-manager.h>
#include <networking/i-web-request.h>

namespace cm {
namespace framework {

    class IObjectFactory
    {
    public:
        virtual ~IObjectFactory() = default;

        virtual models::Client* createClient(QObject* parent) const = 0;

        virtual models::ClientSearch* createClientSearch(QObject* parent, IDatabaseController* databaseController) const = 0;

        virtual controllers::IDatabaseController* createDatabaseController(QObject* parent) const = 0;

        virtual networking::INetworkAccessManager* createNetworkAccessManager(QObject* parent) const = 0;

        virtual networking::IWebRequest* createWebRequest(
            QObject* parent,
            networking::INetworkAccessManager* networkAccessManager,
            const QUrl& url
        ) const = 0;

    };
}}

#endif // I_OBJECT_FACTORY_H
