#ifndef RSS_CHANNEL_H
#define RSS_CHANNEL_H

#include <QObject>

class RssChannel : public QObject
{
    Q_OBJECT
public:
    explicit RssChannel(QObject *parent = nullptr);

signals:
};

#endif // RSS_CHANNEL_H
