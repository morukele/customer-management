#include <QTest>

// add necessary includes here

class ClientTests : public QObject
{
    Q_OBJECT

public:
    ClientTests();
    ~ClientTests();

private slots:
    void initTestCase();
    void init();
    void cleanupTestCase();
    void cleanup();
    void test_case1();
    void test_case2();
};

ClientTests::ClientTests() {}

ClientTests::~ClientTests() {}

void ClientTests::initTestCase()
{
    // code to be executed before the first test function
}

void ClientTests::init()
{
    // code to be executed before each test function
}

void ClientTests::cleanupTestCase()
{
    // code to be executed after the last test function
}

void ClientTests::cleanup()
{
    // code to be executed after each test function
}

void ClientTests::test_case1() {}

void ClientTests::test_case2() {}

// QTEST_APPLESS_MAIN(ClientTests)

#include "client-tests.moc"
