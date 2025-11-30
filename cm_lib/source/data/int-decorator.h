#ifndef INT_DECORATOR_H
#define INT_DECORATOR_H

#include <QObject>
#include <QJsonValue>
#include <QJsonObject>
#include <QScopedPointer>
#include <QString>

#include <cm_lib_global.h>
#include <data/data-decorator.h>

namespace cm {
namespace data {
    class Entity;

    class CM_LIB_EXPORT IntDecorator : public DataDecorator
    {
        Q_OBJECT
        Q_PROPERTY(int ui_value READ value WRITE setValue NOTIFY valueChanged)
    public:
        IntDecorator(
            Entity *parentEntity = nullptr,
            const QString& key = "SomeItemKey",
            const QString& label = "",
            const int& value = 0
        );
        ~IntDecorator();

        IntDecorator& setValue(const int& value);
        const int& value() const;

        QJsonValue jsonValue() const override;
        void update(const QJsonObject& jsonObject) override;

    signals:
        void valueChanged();

    private:
        class Implementation;
        QScopedPointer<Implementation> implementation;
    };
}}

#endif // INT_DECORATOR_H
