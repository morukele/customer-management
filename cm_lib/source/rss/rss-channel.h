#ifndef RSS_CHANNEL_H
#define RSS_CHANNEL_H

#include <QObject>
#include <QDateTime>
#include <QtXml/QDomElement>
#include <QtXml/QDomNode>
#include <QList>
#include <QtQml/QQmlListProperty>
#include <QString>

#include <cm_lib_global.h>
#include <rss/rss-image.h>
#include <rss/rss-item.h>

namespace cm {
namespace rss {
    class RssChannel : public QObject
    {
        Q_OBJECT
    public:
        RssChannel(QObject *parent = nullptr, const QDomNode& domNode = QDomNode());
        ~RssChannel();

        void addItem(RssItem* item);
        const QString& description() const;
        RssImage* image() const;
        const QList<RssItem*>& items() const;
        const QString& link() const;
        void setImage(RssImage* image);
        const QString& title() const;
        QQmlListProperty<RssItem> ui_items();

        static RssChannel* fromXml(const QByteArray& xmlData, QObject* parent = nullptr);

    private:
        class Implementation;
        QScopedPointer<Implementation> implementation;
    };

}}

#endif // RSS_CHANNEL_H
