#ifndef I_NETWORK_ACCESS_MANAGER_H
#define I_NETWORK_ACCESS_MANAGER_H

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkInformation>

namespace cm {
namespace networking {

    class INetworkAccessManager
    {
    public:
        INetworkAccessManager() {}
        virtual ~INetworkAccessManager() {}

        virtual QNetworkReply* get(const QNetworkRequest& request) = 0;
        virtual bool isNetworkAccessible() const = 0;
    };
}}

#endif // I_NETWORK_ACCESS_MANAGER_H
