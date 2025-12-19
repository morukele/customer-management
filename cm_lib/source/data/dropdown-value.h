#ifndef DROPDOWN_VALUE_H
#define DROPDOWN_VALUE_H

#include <QObject>

#include <cm_lib_global.h>

namespace cm {
namespace data {

    class CM_LIB_EXPORT DropDownValue : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(int ui_key MEMBER key CONSTANT)
        Q_PROPERTY(QString ui_description MEMBER description CONSTANT)
    public:
        explicit DropDownValue(QObject *parent = nullptr, int key = 0, const QString& description = "");
        ~DropDownValue();

    public:
        int key{0};
        QString description{""};
    };

}}

#endif // DROPDOWN_VALUE_H
