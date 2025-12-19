#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H

#include <framework/i-object-factory.h>

namespace cm {
namespace framework {

    class CM_LIB_EXPORT ObjectFactory : public IObjectFactory
    {

    public:
        ObjectFactory();

        controllers::IDatabaseController* createDatabaseController(QObject* parent) const override;
    };

}}

#endif // OBJECT_FACTORY_H
