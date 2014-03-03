#ifndef GOOBSERVERDISPATCHER_H
#define GOOBSERVERDISPATCHER_H

#include "../gocoreglobal.h"

#include <QObject>
#include <QVariant>

class GOCORESHARED_EXPORT GoObserverDispatcher : public QObject
{
    Q_OBJECT

private:
    explicit GoObserverDispatcher(QObject *parent = 0);

Q_SIGNALS:
    void updated(const QVariantList &args);
public Q_SLOTS:
    void emitUpdatedSignalWithoutArgs();
private:
    friend class GoObserverScheduler;
};

#endif // GOOBSERVERDISPATCHER_H
