#include <controllers/master-controller.h>

using namespace cm::models;

namespace cm {
namespace controllers {

    class MasterController::Implementation
    {
    public:
        Implementation(MasterController* _masterController)
            : masterController(_masterController)
        {
            databaseController = new DatabaseController(masterController);
            navigationController = new NavigationController(masterController);
            newClient = new Client(masterController);
            clientSearch = new ClientSearch(masterController, databaseController);

            // Initialise this last
            // --------------------
            commandController = new CommandController(
                masterController, databaseController, navigationController, newClient, clientSearch
            );
        }

        MasterController* masterController{nullptr};
        CommandController* commandController{nullptr};
        DatabaseController* databaseController{nullptr};
        NavigationController* navigationController{nullptr};
        Client* newClient{nullptr};
        ClientSearch* clientSearch{nullptr};
        QString welcomeMessage = "Welcome to the Client Management system!";
    };

    MasterController::MasterController(QObject *parent)
        : QObject{parent}
    {
        implementation.reset(new Implementation(this));
    }

    MasterController::~MasterController()
    {
    }

    DatabaseController* MasterController::databaseController()
    {
        return implementation->databaseController;
    }

    NavigationController* MasterController::navigationController()
    {
        return implementation->navigationController;
    }

    CommandController* MasterController::commandController()
    {
        return implementation->commandController;
    }

    const QString& MasterController::welcomeMessage() const
    {
        return implementation->welcomeMessage;
    }

    Client* MasterController::newClient() {
        return implementation->newClient;
    }

    ClientSearch* MasterController::clientSearch() {
        return implementation->clientSearch;
    }

    void MasterController::selectClient(Client* client)
    {
        implementation->navigationController->goEditClientView(client);
    }
}}

