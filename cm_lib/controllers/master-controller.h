#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QString>
#include <cm_lib_global.h>

namespace cm {
    namespace controllers {



    class CM_LIB_EXPORT MasterController : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString ui_welcomeMessage MEMBER welcomeMessage CONSTANT)
    public:
        explicit MasterController(QObject *parent = nullptr);
        QString welcomeMessage = "This is MasterController to Major Oghenemarho";
    signals:
    };
}}

#endif // MASTERCONTROLLER_H
