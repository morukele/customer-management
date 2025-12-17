#ifndef RSS_ITEM_H
#define RSS_ITEM_H

#include <QObject>

class RssItem : public QObject
{
    Q_OBJECT
public:
    explicit RssItem(QObject *parent = nullptr);

signals:
};

#endif // RSS_ITEM_H
