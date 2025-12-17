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
#if QT_VERSION >= QT_VERSION_CHECK(6, 1, 0)
        if (auto* info = QNetworkInformation::instance()) {
            return info->reachability() != QNetworkInformation::Reachability::Disconnected;
        }
        return true;
#else
        return implementation->networkAccessManager.networkAccessible() ==
               QNetworkAccessManager::Accessible;
#endif
    }
}}
