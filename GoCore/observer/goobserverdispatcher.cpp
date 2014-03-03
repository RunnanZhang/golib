#include "goobserverdispatcher.h"

GoObserverDispatcher::GoObserverDispatcher(QObject *parent)
    : QObject(parent)
{
}

void GoObserverDispatcher::emitUpdatedSignalWithoutArgs()
{
    emit updated(QVariantList());
}
