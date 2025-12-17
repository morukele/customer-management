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
            NavigationController* _navigationController,
            Client* _newClient,
            ClientSearch* _clientSearch
        )
            : navigationController(_navigationController)
            , commandController(_commandController)
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

            Command* editClientDeleteCommand = new Command(commandController, QChar(0xf235), "Delete");
            QObject::connect(
                editClientDeleteCommand,
                &Command::executed,
                commandController,
                &CommandController::onEditClientDeleteExecuted
            );

            editClientSaveCommands.append(editClientSaveCommand);
            editClientSaveCommands.append(editClientDeleteCommand);
        }

        QList<Command*> createClientViewContextCommands{};
        QList<Command*> findClientSearchCommands{};
        QList<Command*> editClientSaveCommands{};
        NavigationController* navigationController{nullptr};
        CommandController* commandController{nullptr};
        IDatabaseController *databaseController{nullptr};
        Client* newClient{nullptr};
        Client* selectedClient{nullptr};
        ClientSearch* clientSearch{nullptr};
    };

    CommandController::CommandController(QObject *parent,
        IDatabaseController* databaseController,
        NavigationController* navigationController,
        Client* newClient,
        ClientSearch* clientSearch
    )
        : QObject{parent}
    {
        implementation.reset(
            new Implementation(this, databaseController, navigationController, newClient, clientSearch)
        );
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

        implementation->clientSearch->searchText()->setValue(implementation->selectedClient->id());
        implementation->clientSearch->search();
        implementation->navigationController->goFindClientView();
    }

    void CommandController::setSelectedClient(cm::models::Client* client)
    {
        implementation->selectedClient = client;
    }

    void CommandController::onEditClientDeleteExecuted()
    {
        qDebug() << "You executed the Delete command!";

        implementation->databaseController->deleteRow(
            implementation->selectedClient->key(),
            implementation->selectedClient->id()
        );

        implementation->selectedClient = nullptr;

        qDebug() << "Client deleted";

        implementation->clientSearch->search();
        implementation->navigationController->goDashboardView();
    }
}}
