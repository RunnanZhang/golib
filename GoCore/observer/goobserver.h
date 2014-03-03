#ifndef GOOBSERVER_H
#define GOOBSERVER_H

#include "../gocoreglobal.h"

#include <QObject>
#include <QVariant>

#include "goobserverdispatcher.h"

class GOCORESHARED_EXPORT GoObserver
{
public:
    static void attach(const QObject *sender, const char *signal, const char *name);
    static void detach(const QObject *sender, const char *signal, const char *name);

    static void attach(const char *name, const QObject *receiver, const char *method);
    static void detach(const char *name, const QObject *receiver, const char *method);

public:
    static void notify(const char *name, const QVariantList &args);

public:
    static void notify(const char *name);
    static void notify(const char *name, const QVariant &arg0);
    static void notify(const char *name, const QVariant &arg0,
                       const QVariant &arg1);
    static void notify(const char *name, const QVariant &arg0,
                       const QVariant &arg1, const QVariant &arg2);
    static void notify(const char *name, const QVariant &arg0,
                       const QVariant &arg1, const QVariant &arg2,
                       const QVariant &arg3);
    static void notify(const char *name, const QVariant &arg0,
                       const QVariant &arg1, const QVariant &arg2,
                       const QVariant &arg3, const QVariant &arg4);
    static void notify(const char *name, const QVariant &arg0,
                       const QVariant &arg1, const QVariant &arg2,
                       const QVariant &arg3, const QVariant &arg4,
                       const QVariant &arg5);
    static void notify(const char *name, const QVariant &arg0,
                       const QVariant &arg1, const QVariant &arg2,
                       const QVariant &arg3, const QVariant &arg4,
                       const QVariant &arg5, const QVariant &arg6);
    static void notify(const char *name, const QVariant &arg0,
                       const QVariant &arg1, const QVariant &arg2,
                       const QVariant &arg3, const QVariant &arg4,
                       const QVariant &arg5, const QVariant &arg6,
                       const QVariant &arg7);
    static void notify(const char *name, const QVariant &arg0,
                       const QVariant &arg1, const QVariant &arg2,
                       const QVariant &arg3, const QVariant &arg4,
                       const QVariant &arg5, const QVariant &arg6,
                       const QVariant &arg7, const QVariant &arg8);
    static void notify(const char *name, const QVariant &arg0,
                       const QVariant &arg1, const QVariant &arg2,
                       const QVariant &arg3, const QVariant &arg4,
                       const QVariant &arg5, const QVariant &arg6,
                       const QVariant &arg7, const QVariant &arg8,
                       const QVariant &arg9);

public:
    template <typename Func1>
    static inline QMetaObject::Connection
    attach(const typename QtPrivate::FunctionPointer<Func1>::Object *sender,
           Func1 signal, const char *name)
    {
        GoObserverDispatcher *dispatcher = subjectDispatcher(name, true);
        return QObject::connect(sender, signal,
                                dispatcher, &GoObserverDispatcher::emitUpdatedSignalWithoutArgs,
                                Qt::UniqueConnection);
    }
    template <typename Func1>
    static inline void
    detach(const typename QtPrivate::FunctionPointer<Func1>::Object *sender,
           Func1 signal, const char *name)
    {
        GoObserverDispatcher *dispatcher = subjectDispatcher(name, false);
        if (dispatcher) {
            QObject::disconnect(sender, signal,
                                dispatcher, &GoObserverDispatcher::emitUpdatedSignalWithoutArgs);
        }
    }

    template <typename Func1>
    static inline QMetaObject::Connection
    attach(const char *name,
           const typename QtPrivate::FunctionPointer<Func1>::Object *receiver, Func1 method)
    {
        GoObserverDispatcher *dispatcher = observerDispatcher(name, true);
        return QObject::connect(dispatcher, &GoObserverDispatcher::updated,
                                receiver, method,
                                Qt::UniqueConnection);
    }
    template <typename Func1>
    static inline void
    detach(const char *name,
           const typename QtPrivate::FunctionPointer<Func1>::Object *receiver, Func1 method)
    {
        GoObserverDispatcher *dispatcher = observerDispatcher(name, false);
        if (dispatcher) {
            QObject::disconnect(dispatcher, &GoObserverDispatcher::updated,
                                receiver, method);
        }
    }

    template <typename Func1>
    static inline QMetaObject::Connection
    attach(const char *name, Func1 method)
    {
        GoObserverDispatcher *dispatcher = observerDispatcher(name, true);
        return QObject::connect(dispatcher, &GoObserverDispatcher::updated, method);
    }

private:
    static GoObserverDispatcher *subjectDispatcher(const char *name, bool required);
    static GoObserverDispatcher *observerDispatcher(const char *name, bool required);
};

#endif // GOOBSERVER_H
