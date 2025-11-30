#ifndef STRING_DECORATOR_H
#define STRING_DECORATOR_H

#include <QObject>

class StringDecorator : public QObject
{
    Q_OBJECT
public:
    explicit StringDecorator(QObject *parent = nullptr);

signals:
};

#endif // STRING_DECORATOR_H
