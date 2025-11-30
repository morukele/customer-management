#ifndef ENUMERATOR_DECORATOR_H
#define ENUMERATOR_DECORATOR_H

#include <QObject>

class EnumeratorDecorator : public QObject
{
    Q_OBJECT
public:
    explicit EnumeratorDecorator(QObject *parent = nullptr);

signals:
};

#endif // ENUMERATOR_DECORATOR_H
