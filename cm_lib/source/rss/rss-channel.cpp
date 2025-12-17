#include "rss-channel.h"
#include <QtXml/QDomDocument>

namespace cm {
namespace rss {

    class RssChannel::Implementation
    {

    };

    RssChannel::RssChannel(QObject *parent, const QDomNode& domNode)
        : QObject{parent}
    {}
}}
