#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QString>
#include <QScopedPointer>

#include <cm_lib_global.h>
#include <controllers/navigation-controller.h>

namespace cm {
namespace controllers {

    class CM_LIB_EXPORT MasterController : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString ui_welcomeMessage READ welcomeMessage CONSTANT)
        Q_PROPERTY(cm::controllers::NavigationController* ui_navigationController READ navigationController CONSTANT)

    public:
        explicit MasterController(QObject *parent = nullptr);
        ~MasterController();
        NavigationController* navigationController();
        const QString& welcomeMessage() const;

    private:
        class Implementation;
        QScopedPointer<Implementation> implementation;
    };
}}

#endif // MASTERCONTROLLER_H
