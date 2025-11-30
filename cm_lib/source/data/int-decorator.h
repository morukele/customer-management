#ifndef INT_DECORATOR_H
#define INT_DECORATOR_H

#include <QObject>

class IntDecorator : public QObject
{
    Q_OBJECT
public:
    explicit IntDecorator(QObject *parent = nullptr);

signals:
};

#endif // INT_DECORATOR_H
