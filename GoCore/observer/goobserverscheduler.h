#ifndef GOOBSERVERSCHEDULER_H
#define GOOBSERVERSCHEDULER_H

#include <QObject>
#include <QMutex>
#include <QHash>

class GoObserverDispatcher;

class GoObserverScheduler : public QObject
{
public:
    GoObserverScheduler();
    ~GoObserverScheduler();

public:
    void attach(const QObject *sender, const char *signal, const QString &name);
    void detach(const QObject *sender, const char *signal, const QString &name);

    void attach(const QString &name, const QObject *receiver, const char *method);
    void detach(const QString &name, const QObject *receiver, const char *method);

    void notify(const QString &name, const QVariantList &args);

public:
    GoObserverDispatcher *subjectDispatcher(const QString &name, bool required);
    GoObserverDispatcher *observerDispatcher(const QString &name, bool required);

private:
    QMutex m_subjectMutex;
    QMutex m_observerMutex;

    QHash<QString, GoObserverDispatcher *> m_subjectDispatchers;
    QHash<QString, GoObserverDispatcher *> m_observerDispatchers;
};

GoObserverScheduler *theThreadScheduler();

#endif // GOOBSERVERSCHEDULER_H
