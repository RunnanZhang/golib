#include "goobserver.h"

#include "goobserverscheduler.h"

void GoObserver::attach(const QObject *sender, const char *signal, const char *name)
{
    theThreadScheduler()->attach(sender, signal, QString::fromLatin1(name));
}

void GoObserver::detach(const QObject *sender, const char *signal, const char *name)
{
    theThreadScheduler()->detach(sender, signal, QString::fromLatin1(name));
}

void GoObserver::attach(const char *name, const QObject *receiver, const char *method)
{
    theThreadScheduler()->attach(name, receiver, method);
}

void GoObserver::detach(const char *name, const QObject *receiver, const char *method)
{
    theThreadScheduler()->detach(name, receiver, method);
}

void GoObserver::notify(const char *name, const QVariantList &args)
{
    theThreadScheduler()->notify(QString::fromLatin1(name), args);
}

void GoObserver::notify(const char *name)
{
    theThreadScheduler()->notify(QString::fromLatin1(name), QVariantList());
}

void GoObserver::notify(const char *name, const QVariant &arg0)
{
    theThreadScheduler()->notify(QString::fromLatin1(name),
                                 QVariantList() << arg0);
}

void GoObserver::notify(const char *name, const QVariant &arg0,
                        const QVariant &arg1)
{
    theThreadScheduler()->notify(QString::fromLatin1(name),
                                 QVariantList() << arg0 << arg1);
}

void GoObserver::notify(const char *name, const QVariant &arg0,
                        const QVariant &arg1, const QVariant &arg2)
{
    theThreadScheduler()->notify(QString::fromLatin1(name),
                                 QVariantList() << arg0
                                 << arg1 << arg2);
}

void GoObserver::notify(const char *name, const QVariant &arg0,
                        const QVariant &arg1, const QVariant &arg2,
                        const QVariant &arg3)
{
    theThreadScheduler()->notify(QString::fromLatin1(name),
                                 QVariantList() << arg0
                                 << arg1 << arg2 << arg3);
}

void GoObserver::notify(const char *name, const QVariant &arg0,
                        const QVariant &arg1, const QVariant &arg2,
                        const QVariant &arg3, const QVariant &arg4)
{
    theThreadScheduler()->notify(QString::fromLatin1(name),
                                 QVariantList() << arg0 << arg1
                                 << arg2 << arg3 << arg4);
}

void GoObserver::notify(const char *name, const QVariant &arg0,
                        const QVariant &arg1, const QVariant &arg2,
                        const QVariant &arg3, const QVariant &arg4,
                        const QVariant &arg5)
{
    theThreadScheduler()->notify(QString::fromLatin1(name),
                                 QVariantList() << arg0 << arg1
                                 << arg2 << arg3 << arg4 << arg5);
}

void GoObserver::notify(const char *name, const QVariant &arg0,
                        const QVariant &arg1, const QVariant &arg2,
                        const QVariant &arg3, const QVariant &arg4,
                        const QVariant &arg5, const QVariant &arg6)
{
    theThreadScheduler()->notify(QString::fromLatin1(name),
                                 QVariantList() << arg0 << arg1 << arg2
                                 << arg3 << arg4 << arg5 << arg6);
}

void GoObserver::notify(const char *name, const QVariant &arg0,
                        const QVariant &arg1, const QVariant &arg2,
                        const QVariant &arg3, const QVariant &arg4,
                        const QVariant &arg5, const QVariant &arg6,
                        const QVariant &arg7)
{
    theThreadScheduler()->notify(QString::fromLatin1(name),
                                 QVariantList() << arg0 << arg1 << arg2
                                 << arg3 << arg4 << arg5 << arg6 << arg7);
}

void GoObserver::notify(const char *name, const QVariant &arg0,
                        const QVariant &arg1, const QVariant &arg2,
                        const QVariant &arg3, const QVariant &arg4,
                        const QVariant &arg5, const QVariant &arg6,
                        const QVariant &arg7, const QVariant &arg8)
{
    theThreadScheduler()->notify(QString::fromLatin1(name),
                                 QVariantList() << arg0 << arg1 << arg2 << arg3
                                 << arg4 << arg5 << arg6 << arg7 << arg8);
}

void GoObserver::notify(const char *name, const QVariant &arg0,
                        const QVariant &arg1, const QVariant &arg2,
                        const QVariant &arg3, const QVariant &arg4,
                        const QVariant &arg5, const QVariant &arg6,
                        const QVariant &arg7, const QVariant &arg8,
                        const QVariant &arg9)
{
    theThreadScheduler()->notify(QString::fromLatin1(name),
                                 QVariantList() << arg0 << arg1 << arg2 << arg3
                                 << arg4 << arg5 << arg6 << arg7 << arg8 << arg9);
}

GoObserverDispatcher *GoObserver::subjectDispatcher(const char *name, bool required)
{
    return theThreadScheduler()->subjectDispatcher(QString::fromLatin1(name), required);
}

GoObserverDispatcher *GoObserver::observerDispatcher(const char *name, bool required)
{
    return theThreadScheduler()->observerDispatcher(QString::fromLatin1(name), required);
}
