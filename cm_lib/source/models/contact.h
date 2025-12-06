#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include <data/string-decorator.h>
#include <data/enumerator-decorator.h>
#include <data/entity.h>

#include <cm_lib_global.h>

namespace cm {
namespace models {

class CM_LIB_EXPORT Contact : public data::Entity
    {
        Q_OBJECT
        Q_PROPERTY(cm::data::EnumeratorDecorator* ui_contactType MEMBER contactType CONSTANT)
        Q_PROPERTY(cm::data::StringDecorator* ui_address MEMBER address CONSTANT)

    public:
        enum eContactType {
            Unknown = 0,
            Telephone,
            Email,
            Fax
        };

    public:
        explicit Contact(QObject *parent = nullptr);
        Contact(QObject *parent, const QJsonObject& json);

        data::EnumeratorDecorator* contactType{nullptr};
        data::StringDecorator* address{nullptr};
        static std::map<int, QString> contactTypeMapper;

    signals:
    };
}}

#endif // CONTACT_H
