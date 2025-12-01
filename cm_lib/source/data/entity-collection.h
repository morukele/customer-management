#ifndef ENTITY_COLLECTION_H
#define ENTITY_COLLECTION_H

#include <QObject>
#include <QJsonArray>
#include <QJsonValue>

#include <QtCore/qjsonobject.h>
#include <cm_lib_global.h>

namespace cm {
namespace data {
    class Entity;

    class CM_LIB_EXPORT EntityCollectionObject : public QObject
    {
        Q_OBJECT

    public:
        EntityCollectionObject(QObject* _parent = nullptr) : QObject(_parent){}
        virtual ~EntityCollectionObject() {}

    signals:
        void collectionChanged();
    };

    class EntityCollectionBase : public EntityCollectionObject
    {
    public:
        EntityCollectionBase(QObject* parent = nullptr, const QString& key = "SomeCollectionKey")
            : EntityCollectionObject(parent)
            , key(key)
        {}

        virtual ~EntityCollectionBase() {}

        QString getKey() const
        {
            return key;
        }

        virtual void clear() = 0;
        virtual void update(const QJsonArray& json) = 0;
        virtual std::vector<Entity*> baseEntities() = 0;

        template <class T>
        QList<T*>& derivedEntities();

        template <class T>
        T* addEntity(T* entity);

    private:
        QString key;
    };

    template <typename T>
    class EntityCollection : public EntityCollectionBase
    {
    public:
        EntityCollection(QObject* parent = nullptr, const QString& key = "SomeCollectionKey")
            : EntityCollectionBase(parent, key)
        {
        }

        ~EntityCollection()
        {
        }

        void clear() override
        {
            for (auto entity : collection) {
                entity->deleteLater();
            }
            collection.clear();
        }

        void update (const QJsonArray& jsonArray) override
        {
            clear();
            for (const QJsonValue& jsonValue : jsonArray) {
                addEntity(new T(this, jsonValue.toObject()));
            }
        }


    private:
        QList<T*> collection;
    };
}}

#endif // ENTITY_COLLECTION_H
