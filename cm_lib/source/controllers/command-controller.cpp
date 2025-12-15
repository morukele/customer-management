#include "command-controller.h"

#include <QList>
#include <QDebug>

using namespace cm::framework;
using namespace cm::models;

namespace cm {
namespace controllers {

    class CommandController::Implementation
    {
    public:
        Implementation(CommandController* _commandController,
            IDatabaseController* _databaseController,
            Client* _newClient,
            ClientSearch* _clientSearch
        )
            : commandController(_commandController)
            , databaseController(_databaseController)
            , newClient(_newClient)
            , clientSearch(_clientSearch)
        {
            Command* createClientSaveCommand = new Command(commandController, QChar( 0xf0c7 ), "Save" ); // create command
            QObject::connect(
                createClientSaveCommand,
                &Command::executed,
                commandController,
                &CommandController::onCreateClientSaveExecuted
            ); // set up command in QT GUI view
            createClientViewContextCommands.append(createClientSaveCommand); // add command to the list of commands

            Command* findClientSearchCommand = new Command(commandController, QChar(0xf002), "Search");
            QObject::connect(
                findClientSearchCommand,
                &Command::executed,
                commandController,
                &CommandController::onFindClientSearchExecuted
            );
            findClientSearchCommands.append(findClientSearchCommand);

            Command* editClientSaveCommand = new Command(commandController, QChar(0xf0c7), "Save");
            QObject::connect(
                editClientSaveCommand,
                &Command::executed,
                commandController,
                &CommandController::onEditClientSaveExecuted
                );
            editClientSaveCommands.append(editClientSaveCommand);
        }

        CommandController* commandController{nullptr};
        QList<Command*> createClientViewContextCommands{};
        QList<Command*> findClientSearchCommands{};
        QList<Command*> editClientSaveCommands{};
        IDatabaseController *databaseController{nullptr};
        Client* newClient{nullptr};
        Client* selectedClient{nullptr};
        ClientSearch* clientSearch{nullptr};
    };

    CommandController::CommandController(QObject *parent,
        IDatabaseController* databaseController,
        Client* newClient,
        ClientSearch* clientSearch
    )
        : QObject{parent}
    {
        implementation.reset(new Implementation(this, databaseController, newClient, clientSearch));
    }

    CommandController::~CommandController()
    {
    }

    QQmlListProperty<Command> CommandController::ui_createClientViewContextCommands()
    {
        return QQmlListProperty<Command>(this, &implementation->createClientViewContextCommands);
    }

    QQmlListProperty<Command> CommandController::ui_findClientViewContextCommands()
    {
        return QQmlListProperty<Command>(this, &implementation->findClientSearchCommands);
    }

    QQmlListProperty<Command> CommandController::ui_editClientViewContextCommands()
    {
        return QQmlListProperty<Command>(this, &implementation->editClientSaveCommands);
    }

    void CommandController::onCreateClientSaveExecuted()
    {
        qDebug() << "You executed the Save command!";

        implementation->databaseController->createRow(
            implementation->newClient->key(),
            implementation->newClient->id(),
            implementation->newClient->toJson()
        );

        qDebug() << "New client saved.";
    }

    void CommandController::onFindClientSearchExecuted()
    {
        qDebug() << "You executed the Search command!";

        implementation->clientSearch->search();
    }

    void CommandController::onEditClientSaveExecuted()
    {
        qDebug() << "You executed the Save command!";

        implementation->databaseController->updateRow(
            implementation->selectedClient->key(),
            implementation->selectedClient->id(),
            implementation->selectedClient->toJson()
        );

        qDebug() << "Update client saved.";
    }

    void CommandController::setSelectedClient(cm::models::Client* client)
    {
        implementation->selectedClient = client;
    }
}}
