#include "enumerator-decorator.h"

namespace cm {
namespace data {

    class EnumeratorDecorator::Implementation
    {
    public:
        Implementation(
            EnumeratorDecorator* _enumeratorDecorator,
            const int& _value,
            const std::map<int, QString>& _descriptionMapper
        )
            : enumeratorDecorator(_enumeratorDecorator)
            , value(_value)
            , descriptionMapper(_descriptionMapper)
        {
        }

        EnumeratorDecorator* enumeratorDecorator{nullptr};
        int value;
        std::map<int, QString> descriptionMapper;
    };

    EnumeratorDecorator::EnumeratorDecorator(
        Entity* parentEntity,
        const QString& key,
        const QString& label,
        int value,
        const std::map<int, QString>& descriptionMapper
        )
        : DataDecorator(parentEntity, key, label)
    {
        implementation.reset(new Implementation(this, value, descriptionMapper));
    }

    EnumeratorDecorator::~EnumeratorDecorator()
    {
    }

    int EnumeratorDecorator::value() const
    {
        return implementation->value;
    }

    QString EnumeratorDecorator::valueDescription() const
    {
        // .find(key) returns an end() if "key" not found in map.
        if (implementation->descriptionMapper.find(implementation->value)
            != implementation->descriptionMapper.end()) {
            return implementation->descriptionMapper.at(implementation->value);
        } else {
            return {};
        }
    }

    EnumeratorDecorator& EnumeratorDecorator::setValue(const int& value) {
        if (value != implementation->value) {
            implementation->value = value;
            emit valueChanged();
        }
        return *this;
    }

    QJsonValue EnumeratorDecorator::jsonValue() const {
        return QJsonValue::fromVariant(QVariant(implementation->value));
    }

    void EnumeratorDecorator::update(const QJsonObject& _jsonObject) {
        if (_jsonObject.contains(key())) {
            setValue(_jsonObject.value(key()).toInt());
        } else {
            setValue(0);
        }
    }
}}
