#include "master-controller-tests.h"

namespace cm {
namespace controllers {
    // Instance
    static MasterControllerTests instance;

    MasterControllerTests::MasterControllerTests()
        : TestSuite{"MasterControllerTests"}
    {
    }

    // Scaffolding
    void MasterControllerTests::initTestCase()
    {
    }

    void MasterControllerTests::cleanupTestCase()
    {
    }

    void MasterControllerTests::init()
    {
    }

    void MasterControllerTests::cleanup()
    {
    }

    // Tests
    void MasterControllerTests::welcomeMessage_returnsCorrectMessage()
    {
        QCOMPARE(masterController.welcomeMessage(), QString("Welcome to the Client Management system!"));
    }
}}
