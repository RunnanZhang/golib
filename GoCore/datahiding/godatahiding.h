#ifndef GODATAHIDING_H
#define GODATAHIDING_H

#include "../gocoreglobal.h"

class GoPublicClass;

class GOCORESHARED_EXPORT GoPrivateInfo
{
public:
    GoPrivateInfo();
public:
    virtual ~GoPrivateInfo();

public:
    GoPublicClass *const _go_pptr;
};

class GOCORESHARED_EXPORT GoPublicClass
{
protected:
    GoPublicClass();
public:
    virtual ~GoPublicClass();

protected:
    GoPublicClass(GoPrivateInfo &pi);
protected:
    GoPrivateInfo *const _go_pptr;
};

#define GO_PRIVATE_INFO(Class)                                      \
    private:                                                        \
    inline Class##Private *go()                                     \
    { return reinterpret_cast<Class##Private *>(_go_pptr); }        \
    inline const Class##Private *go() const                         \
    { return reinterpret_cast<const Class##Private *>(_go_pptr); }

#define GO_PUBLIC_CLASS(Class)                                      \
    private:                                                        \
    inline Class *go()                                              \
    { return static_cast<Class *>(_go_pptr); }                      \
    inline const Class *go() const                                  \
    { return static_cast<const Class *>(_go_pptr); }

#endif // GODATAHIDING_H
