#ifndef CM_LIB_GLOBAL_H
#define CM_LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CM_LIB_LIBRARY)
#define CM_LIB_EXPORT Q_DECL_EXPORT
#else
#define CM_LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // CM_LIB_GLOBAL_H
