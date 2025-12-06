#ifndef MASTER_CONTROLLER_H
#define MASTER_CONTROLLER_H

#include <QObject>
#include <QString>
#include <QScopedPointer>

#include <cm_lib_global.h>
#include <controllers/navigation-controller.h>
#include <controllers/command-controller.h>

using namespace cm::models;

namespace cm {
namespace controllers {

    class CM_LIB_EXPORT MasterController : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString ui_welcomeMessage READ welcomeMessage CONSTANT)
        Q_PROPERTY(cm::controllers::NavigationController* ui_navigationController READ navigationController CONSTANT)
        Q_PROPERTY(cm::controllers::CommandController* ui_commandController READ commandController CONSTANT)
        Q_PROPERTY(cm::models::Client* ui_newClient READ newClient CONSTANT)

    public:
        explicit MasterController(QObject *parent = nullptr);
        ~MasterController();
        NavigationController* navigationController();
        CommandController* commandController();
        Client* newClient();
        const QString& welcomeMessage() const;

    private:
        class Implementation;
        QScopedPointer<Implementation> implementation;
    };
}}

#endif // MASTER_CONTROLLER_H
