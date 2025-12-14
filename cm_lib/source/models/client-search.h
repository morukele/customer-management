#ifndef CLIENT_SEARCH_H
#define CLIENT_SEARCH_H

#include <QObject>
#include <QScopedPointer>

#include <cm_lib_global.h>
#include <controllers/i-database-controller.h>
#include <data/string-decorator.h>
#include <data/entity.h>
#include <data/entity-collection.h>
#include <models/client.h>

namespace cm {
namespace models {
class CM_LIB_EXPORT ClientSearch : public data::Entity
    {
        Q_OBJECT
        Q_PROPERTY(cm::data::StringDecorator* ui_searchText READ searchText CONSTANT)
        Q_PROPERTY(QQmlListProperty<cm::models::Client> ui_searchResults READ ui_searchResults NOTIFY searchResultsChanged)
    public:
        explicit ClientSearch(QObject *parent = nullptr, controllers::IDatabaseController* databaseController = nullptr);
        ~ClientSearch();

        data::StringDecorator* searchText();
        QQmlListProperty<Client> ui_searchResults();
        void search();

    signals:
        void searchResultsChanged();

    private:
        class Implementation;
        QScopedPointer<Implementation> implementation;
    };
}}

#endif // CLIENT_SEARCH_H
