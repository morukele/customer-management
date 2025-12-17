#ifndef RSS_ITEM_H
#define RSS_ITEM_H

#include <QObject>
#include <QDateTime>
#include <QScopedPointer>
#include <QtXml/QDomNode>
#include <cm_lib_global.h>

namespace cm {
namespace rss {

    class CM_LIB_EXPORT RssItem : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString ui_description READ description CONSTANT)
        Q_PROPERTY(QString ui_link READ link CONSTANT)
        Q_PROPERTY(QDateTime ui_pubDate READ pubDate CONSTANT)
        Q_PROPERTY(QString ui_title READ title CONSTANT)
    public:
        RssItem(QObject *parent = nullptr, const QDomNode& domNode = QDomNode());
        ~RssItem();

        const QString& description() const;
        const QString& link() const;
        const QDateTime& pubDate() const;
        const QString& title() const;

    private:
        class Implementation;
        QScopedPointer<Implementation> implementation;
    };
}}

#endif // RSS_ITEM_H
