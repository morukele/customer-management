#include "network-access-manager.h"

namespace cm {
namespace networking {
    class NetworkAccessManager::Implementation
    {
    public:
        Implementation(){}
        QNetworkAccessManager networkAccessManager;
    };

    NetworkAccessManager::NetworkAccessManager(QObject *parent)
        : QObject{parent}, INetworkAccessManager()
    {
        implementation.reset(new Implementation());
    }

    NetworkAccessManager::~NetworkAccessManager()
    {
    }

    QNetworkReply* NetworkAccessManager::get(const QNetworkRequest& request)
    {
        return implementation->networkAccessManager.get(request);
    }

    bool NetworkAccessManager::isNetworkAccessible() const
    {
        // since we are querying with this function we don't need to store it in the pImpl
        auto *netInfo = QNetworkInformation::instance();
        return netInfo && netInfo->reachability() ==
               QNetworkInformation::Reachability::Online;
    }
}}
