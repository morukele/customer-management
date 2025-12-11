#ifndef DATE_TIME_DECORATOR_TESTS_H
#define DATE_TIME_DECORATOR_TESTS_H

#include <QtTest>

#include <data/date-time-decorator.h>
#include <test-suite.h>

namespace cm {
namespace data {
    class DateTimeDecoratorTests : public TestSuite
    {
        Q_OBJECT

    public:
        DateTimeDecoratorTests();

    private slots:
        void constructor_givenNoParameters_setsDefaultProperties();
        void constructor_givenParameters_setsProperties();
        void setValue_givenNewValue_updatesValueAndEmitsSignal();
        void setValue_givenSameValue_takesNoAction();
        void jsonValue_whenDefaultValue_returnsJson();
        void jsonValue_whenValueSet_returnsJson();
        void update_whenPresentInJson_updatesValue();
        void update_whenNotPresentInJson_updatesValueToDefault();
    };
}}

#endif // DATE_TIME_DECORATOR_TESTS_H
