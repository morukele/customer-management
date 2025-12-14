#ifndef COMMAND_CONTROLLER_H
#define COMMAND_CONTROLLER_H

#include <QObject>
#include <QtQml/QQmlListProperty>

#include <cm_lib_global.h>
#include <controllers/i-database-controller.h>
#include <framework/command.h>
#include <models/client.h>

namespace cm {
namespace controllers {
    class CM_LIB_EXPORT CommandController : public QObject
    {
        Q_OBJECT
        Q_PROPERTY( // This macro expects each keyword and value to appear on the same line
            QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommands
            READ ui_createClientViewContextCommands
            CONSTANT
        )
    public:
        explicit CommandController(QObject *_parent = nullptr, IDatabaseController *databaseController = nullptr, models::Client *newClient = nullptr);
        ~CommandController();

        QQmlListProperty<framework::Command> ui_createClientViewContextCommands();

    public slots:
        void onCreateClientSaveExecuted();

    private:
        class Implementation;
        QScopedPointer<Implementation> implementation;
    };
}}

#endif // COMMAND_CONTROLLER_H
