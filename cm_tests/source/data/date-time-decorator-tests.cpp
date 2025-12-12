#include "date-time-decorator-tests.h"

#include <QSignalSpy>
#include <QDateTime>
#include <QDebug>

#include<data/entity.h>

namespace cm {
namespace data {
    // Instance
    static DateTimeDecoratorTests instance;

    DateTimeDecoratorTests::DateTimeDecoratorTests()
        : TestSuite("DateTimeDecoratorTests")
    {
    }

    // Tests
    void DateTimeDecoratorTests::constructor_givenNoParameters_setsDefaultProperties()
    {
        DateTimeDecorator decorator;

        QCOMPARE(decorator.parentEntity(), nullptr);
        QCOMPARE(decorator.key(), QString("SomeItemKey"));
        QCOMPARE(decorator.label(), QString(""));
        QCOMPARE(decorator.value(), QDateTime());
        QCOMPARE(decorator.toPrettyDateString(), QString("Not set"));
        QCOMPARE(decorator.toPrettyTimeString(), QString("Not set"));
        QCOMPARE(decorator.toPrettyString(), QString("Not set"));
        QCOMPARE(decorator.toIso8601String(), QString(""));
    }

    void DateTimeDecoratorTests::constructor_givenParameters_setsProperties()
    {
        const QDateTime& dateTime = QDateTime::currentDateTime();
        Entity parentEntity;
        DateTimeDecorator decorator(&parentEntity, "Test Key", "Test Label", dateTime);

        QCOMPARE(decorator.parentEntity(), &parentEntity);
        QCOMPARE(decorator.key(), QString("Test Key"));
        QCOMPARE(decorator.label(), QString("Test Label"));
        QCOMPARE(decorator.value(), dateTime);
    }

    // Test for pretty string
    void DateTimeDecoratorTests::value_prettyString_returnsPrettyString()
    {
        const QDateTime& dateTime = QDateTime::currentDateTime();
        Entity parentEntity;
        DateTimeDecorator decorator(&parentEntity, "Test Key", "Test Label", dateTime);

        QCOMPARE(decorator.parentEntity(), &parentEntity);
        QCOMPARE(decorator.key(), QString("Test Key"));
        QCOMPARE(decorator.label(), QString("Test Label"));
        QCOMPARE(decorator.value(), dateTime);
        QCOMPARE(decorator.toIso8601String(), dateTime.toString(Qt::ISODate));
        QCOMPARE(decorator.toPrettyString(), dateTime.toString("ddd d MMM yyyy @ HH:mm::ss"));
        QCOMPARE(decorator.toPrettyDateString(), dateTime.toString("d MMM yyyy"));
        QCOMPARE(decorator.toPrettyTimeString(), dateTime.toString("hh:mm ap"));
    }

    void DateTimeDecoratorTests::setValue_givenNewValue_updatesValueAndEmitsSignal()
    {
        DateTimeDecorator decorator;
        QSignalSpy valueChangedSpy(&decorator, &DateTimeDecorator::valueChanged);

        QCOMPARE(decorator.value(), QDateTime());

        const QDateTime& dateTime = QDateTime::currentDateTime();
        decorator.setValue(dateTime);
        QCOMPARE(decorator.value(), dateTime);
        QCOMPARE(valueChangedSpy.count(), 1);
    }

    void DateTimeDecoratorTests::setValue_givenSameValue_takesNoAction()
    {
        Entity parentEntity;
        const QDateTime& dateTime = QDateTime::currentDateTime();
        DateTimeDecorator decorator(&parentEntity, "Test Key", "Test Label", dateTime);
        QSignalSpy valueChangedSpy(&decorator, &DateTimeDecorator::valueChanged);

        QCOMPARE(decorator.value(), dateTime);
        decorator.setValue(dateTime);
        QCOMPARE(decorator.value(), dateTime);
        QCOMPARE(valueChangedSpy.count(), 0);
    }

    void DateTimeDecoratorTests::jsonValue_whenDefaultValue_returnsJson()
    {
        DateTimeDecorator decorator;
        QJsonValue value = QJsonValue::fromVariant(QVariant(QDateTime()));

        QCOMPARE(decorator.jsonValue(), value);
    }

    void DateTimeDecoratorTests::jsonValue_whenValueSet_returnsJson()
    {
        DateTimeDecorator decorator;
        const QDateTime& dateTime = QDateTime::currentDateTime();
        decorator.setValue(dateTime);
        QJsonValue value = QJsonValue::fromVariant(QVariant(dateTime));

        QCOMPARE(decorator.jsonValue(), value);
    }

    void DateTimeDecoratorTests::update_whenPresentInJson_updatesValue()
    {
        Entity parentEntity;
        const QDateTime& dateTime = QDateTime::currentDateTime();
        DateTimeDecorator decorator(&parentEntity, "Test Key", "Test Label", dateTime);
        QSignalSpy valueChangedSpy(&decorator, &DateTimeDecorator::valueChanged);

        QCOMPARE(decorator.value(), dateTime);

        QJsonObject jsonObject;
        jsonObject.insert("Key 1", "Value 1");
        jsonObject.insert("Key 2", 123);
        // Adding two minutes, to make time difference reasonable
        const QDateTime& newDateTime = QDateTime::currentDateTime().addSecs(120);
        QJsonValue value = QJsonValue::fromVariant(QVariant(newDateTime));
        jsonObject.insert("Test Key", value);
        decorator.update(jsonObject);

        QCOMPARE(decorator.value(), newDateTime);
        QCOMPARE(valueChangedSpy.count(), 1);
    }

    void DateTimeDecoratorTests::update_whenNotPresentInJson_updatesValueToDefault()
    {
        Entity parentEntity;
        const QDateTime& dateTime = QDateTime::currentDateTime();
        DateTimeDecorator decorator(&parentEntity, "Test Key", "Test Label", dateTime);
        QSignalSpy valueChangedSpy(&decorator, &DateTimeDecorator::valueChanged);

        QCOMPARE(decorator.value(), dateTime);

        QJsonObject jsonObject;
        jsonObject.insert("Key 1", "Value 1");
        jsonObject.insert("Key 2", 123);
        jsonObject.insert("Key 3", 3);
        decorator.update(jsonObject);

        QCOMPARE(decorator.value(), QDateTime());
        QCOMPARE(valueChangedSpy.count(), 1);
    }
}}
