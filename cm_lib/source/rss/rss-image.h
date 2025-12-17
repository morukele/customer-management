#ifndef RSS_IMAGE_H
#define RSS_IMAGE_H

#include <QObject>
#include <QScopedPointer>
#include <QtXml/QDomNode>
#include <cm_lib_global.h>

namespace cm {
namespace rss {

    class CM_LIB_EXPORT RssImage : public QObject
    {
        Q_OBJECT
    public:
        explicit RssImage(QObject *parent = nullptr, const QDomNode& domNode = QDomNode());
        ~RssImage();

        quint16 height() const;
        const QString& link() const;
        const QString& title() const;
        const QString& url() const;
        quint16 width() const;

    private:
        class Implementation;
        QScopedPointer<Implementation> implementation;
    };

}}

#endif // RSS_IMAGE_H
