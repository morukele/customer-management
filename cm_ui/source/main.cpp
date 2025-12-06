#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <controllers/master-controller.h>
#include <controllers/command-controller.h>
#include <data/int-decorator.h>
#include <data/date-time-decorator.h>
#include <data/int-decorator.h>
#include <data/string-decorator.h>
#include <models/address.h>
#include <models/appointment.h>
#include <models/client.h>
#include <models/contact.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    // controller: register the master controller type
    // -----------------------------------------------
    qmlRegisterType<cm::controllers::MasterController>("CM", 1, 0, "MasterController");
    qmlRegisterType<cm::controllers::NavigationController>("CM", 1, 0, "NavigationController");
    qmlRegisterType<cm::controllers::CommandController>("CM", 1, 0, "CommandController");
    qmlRegisterType<cm::framework::Command>("CM", 1, 0, "Command");

    // model: register the models and data type
    //-----------------------------------------
    qmlRegisterType<cm::data::DateTimeDecorator>("CM", 1, 0, "DateTimeDecorator");
    qmlRegisterType<cm::data::EnumeratorDecorator>("CM", 1, 0, "EnumeratorDecorator");
    qmlRegisterType<cm::data::IntDecorator>("CM", 1, 0, "IntDecorator");
    qmlRegisterType<cm::data::StringDecorator>("CM", 1, 0, "StringDecorator");
    qmlRegisterType<cm::models::Address>("CM", 1, 0, "Address");
    qmlRegisterType<cm::models::Appointment>("CM", 1, 0, "Appointment");
    qmlRegisterType<cm::models::Client>("CM", 1, 0, "Client");
    qmlRegisterType<cm::models::Contact>("CM", 1, 0, "Contact");

    cm::controllers::MasterController masterController;

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    const QUrl url(QStringLiteral("qrc:/views/MasterView.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection
    );

    engine.rootContext()->setContextProperty("masterController", &masterController);
    engine.load(url);

    return app.exec();
}
