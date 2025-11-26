#ifndef NAVIGATION_CONTROLLER_H
#define NAVIGATION_CONTROLLER_H

#include <QObject>

#include <cm_lib_global.h>
#include <models/client.h>

namespace cm {
namespace controllers{

    class CM_LIB_EXPORT NavigationController : public QObject {
        Q_OBJECT

    public:
        explicit NavigationController(QObject* _parent = nullptr) : QObject(_parent) {}

    signals:
        void goCreateClientView();
        void goDashboardView();
        void goEditClientView(cm::models::Client* client);
        void goFindClientView();
    };
}}

#endif // NAVIGATION_CONTROLLER_H
