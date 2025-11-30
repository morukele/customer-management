#ifndef STRING_DECORATOR_H
#define STRING_DECORATOR_H

#include <QObject>
#include <QJsonValue>
#include <QJsonValue>
#include <QScopedPointer>
#include <QString>

#include <cm_lib_global.h>
#include <data/data-decorator.h>

namespace cm {
namespace data {
    class CM_LIB_EXPORT StringDecorator : public DataDecorator
    {
        Q_OBJECT
        Q_PROPERTY(QString ui_value READ value WRITE setValue NOTIFY valueChanged)
    public:
        StringDecorator(
            Entity *parentEntity = nullptr,
            const QString& key = "SomeItemKey",
            const QString& label = "",
            const QString& value = ""
        );
        ~StringDecorator();

        StringDecorator& setValue(const QString& value);
        const QString& value() const;

        QJsonValue jsonValue() const override;
        void update(const QJsonObject& jsonObject) override;

    signals:
        void valueChanged();

    private:
        class Implementation;
        QScopedPointer<Implementation> implementation;
    };
}}

#endif // STRING_DECORATOR_H
