#ifndef GOCOREGLOBAL_H
#define GOCOREGLOBAL_H

#include <QtCore/QtGlobal>

#if defined(GOCORE_LIBRARY)
#  define GOCORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define GOCORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GOCOREGLOBAL_H
