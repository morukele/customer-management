#include "object-factory.h"

#include <controllers/database-controller.h>

namespace cm {
namespace framework {

    ObjectFactory::ObjectFactory()
        : IObjectFactory()
    {

    }

    IDatabaseController* ObjectFactory::createDatabaseController(QObject* parent) const
    {
        return new DatabaseController(parent);
    }
}}
