#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <QObject>
#include <data/string-decorator.h>
#include <data/date-time-decorator.h>
#include <data/entity.h>

#include <cm_lib_global.h>

namespace cm {
namespace models {
class CM_LIB_EXPORT Appointment : public data::Entity
    {
        Q_OBJECT
        Q_PROPERTY(cm::data::DateTimeDecorator* ui_startAt MEMBER startAt CONSTANT)
        Q_PROPERTY(cm::data::DateTimeDecorator* ui_endAt MEMBER endAt CONSTANT)
        Q_PROPERTY(cm::data::StringDecorator* ui_notes MEMBER notes CONSTANT)
    public:
        explicit Appointment(QObject *parent = nullptr);
        Appointment(QObject *parent, const QJsonObject& json);

        data::DateTimeDecorator* startAt{nullptr};
        data::DateTimeDecorator* endAt{nullptr};
        data::StringDecorator* notes{nullptr};

    signals:
    };
}}

#endif // APPOINTMENT_H
