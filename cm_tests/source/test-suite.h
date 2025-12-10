#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <QObject>
#include <Qstring>
#include <QtTest/QtTest>

#include <vector>


namespace cm {
    class TestSuite : public QObject
    {
    public:
        explicit TestSuite(const QString& _testName = "");
        virtual ~TestSuite();

        QString testName;
        static std::vector<TestSuite*>& testList();
    };
}

#endif // TEST_SUITE_H
