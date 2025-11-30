#ifndef DATA_DECORATOR_H
#define DATA_DECORATOR_H

#include <QObject>
#include <QJsonValue>
#include <QJsonObject>
#include <QScopedPointer>

#include <cm_lib_global.h>

namespace cm {
    namespace data {

    class Entity;

    class CM_LIB_EXPORT DataDecorator : public QObject
    {
        Q_OBJECT
        Q_PROPERTY( QString ui_label READ label CONSTANT )
    public:
        DataDecorator(
            Entity* parent = nullptr,
            const QString& key = "SomeItemKey",
            const QString& label = ""
        );
        virtual ~DataDecorator(); // destructor

        const QString& key() const;
        const QString& label() const;
        Entity* parentEntity();

        virtual QJsonValue jsonValue() const = 0;
        virtual void update(const QJsonObject& jsonObject) = 0;

    private:
        class Implementation;
        QScopedPointer<Implementation> implementation;
    };
}}

#endif // DATA_DECORATOR_H
