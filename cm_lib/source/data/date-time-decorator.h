#ifndef DATE_TIME_DECORATOR_H
#define DATE_TIME_DECORATOR_H

#include <QObject>

class DateTimeDecorator : public QObject
{
    Q_OBJECT
public:
    explicit DateTimeDecorator(QObject *parent = nullptr);

signals:
};

#endif // DATE_TIME_DECORATOR_H
