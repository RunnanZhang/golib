#include "goobserverscheduler.h"

#include <QList>

#include <QThreadStorage>
#include <QSharedPointer>

#include "goobserverdispatcher.h"

class GoGlobalScheduler
{
public:
    QMutex schedulersMutex;
    QList<GoObserverScheduler *> schedulers;
};

Q_GLOBAL_STATIC(GoGlobalScheduler, theGlobalScheduler)

QThreadStorage<QSharedPointer<GoObserverScheduler> > g_threadSchedulers;

GoObserverScheduler *theThreadScheduler()
{
    if (!g_threadSchedulers.hasLocalData()) {
        QSharedPointer<GoObserverScheduler> scheduler(new GoObserverScheduler());
        g_threadSchedulers.setLocalData(scheduler);
    }
    return g_threadSchedulers.localData().data();
}

GoObserverScheduler::GoObserverScheduler()
{
    QMutexLocker globalLocker(&(theGlobalScheduler()->schedulersMutex));
    theGlobalScheduler()->schedulers.append(this);
}

GoObserverScheduler::~GoObserverScheduler()
{
    QMutexLocker globalLocker(&(theGlobalScheduler()->schedulersMutex));
    theGlobalScheduler()->schedulers.removeOne(this);
}

void GoObserverScheduler::attach(const QObject *sender, const char *signal, const QString &name)
{
    GoObserverDispatcher *dispatcher = subjectDispatcher(name, true);
    QObject::connect(sender, signal,
                     dispatcher, SLOT(emitUpdatedSignalWithoutArgs()),
                     Qt::UniqueConnection);
}

void GoObserverScheduler::detach(const QObject *sender, const char *signal, const QString &name)
{
    GoObserverDispatcher *dispatcher = subjectDispatcher(name, false);
    if (dispatcher) {
        QObject::disconnect(sender, signal,
                            dispatcher, SLOT(emitUpdatedSignalWithoutArgs()));
    }
}

void GoObserverScheduler::attach(const QString &name, const QObject *receiver, const char *method)
{
    GoObserverDispatcher *dispatcher = observerDispatcher(name, true);
    QObject::connect(dispatcher, SIGNAL(updated(QVariantList)),
                     receiver, method,
                     Qt::UniqueConnection);
}

void GoObserverScheduler::detach(const QString &name, const QObject *receiver, const char *method)
{
    GoObserverDispatcher *dispatcher = observerDispatcher(name, false);
    if (dispatcher) {
        QObject::disconnect(dispatcher, SIGNAL(updated(QVariantList)),
                            receiver, method);
    }
}

void GoObserverScheduler::notify(const QString &name, const QVariantList &args)
{
    subjectDispatcher(name, true)->updated(args);
}

GoObserverDispatcher *GoObserverScheduler::subjectDispatcher(const QString &name, bool required)
{
    GoObserverDispatcher *subjectDispatcher = m_subjectDispatchers.value(name);
    if (!subjectDispatcher && required) {
        subjectDispatcher = new GoObserverDispatcher(this);
        m_subjectDispatchers.insert(name, subjectDispatcher);

        QMutexLocker globalLocker(&(theGlobalScheduler()->schedulersMutex));
        Q_FOREACH (GoObserverScheduler *scheduler, theGlobalScheduler()->schedulers) {
            QMutexLocker locker(&scheduler->m_observerMutex);
            GoObserverDispatcher *observerDispatcher
                    = scheduler->m_observerDispatchers.value(name);
            if (observerDispatcher) {
                QObject::connect(subjectDispatcher, &GoObserverDispatcher::updated,
                                 observerDispatcher, &GoObserverDispatcher::updated);
            }
        }
    }
    return subjectDispatcher;
}

GoObserverDispatcher *GoObserverScheduler::observerDispatcher(const QString &name, bool required)
{
    GoObserverDispatcher *observerDispatcher = m_observerDispatchers.value(name);
    if (!observerDispatcher && required) {
        observerDispatcher = new GoObserverDispatcher(this);
        m_observerDispatchers.insert(name, observerDispatcher);

        QMutexLocker globalLocker(&(theGlobalScheduler()->schedulersMutex));
        Q_FOREACH (GoObserverScheduler *scheduler, theGlobalScheduler()->schedulers) {
            QMutexLocker locker(&scheduler->m_subjectMutex);
            GoObserverDispatcher *subjectDispatcher
                    = scheduler->m_subjectDispatchers.value(name);
            if (subjectDispatcher) {
                QObject::connect(subjectDispatcher, &GoObserverDispatcher::updated,
                                 observerDispatcher, &GoObserverDispatcher::updated);
            }
        }
    }
    return observerDispatcher;
}
