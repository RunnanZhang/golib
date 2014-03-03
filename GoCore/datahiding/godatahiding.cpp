#include "godatahiding.h"

GoPrivateInfo::GoPrivateInfo()
    : _go_pptr(0)
{
}

GoPrivateInfo::~GoPrivateInfo()
{
    *const_cast<GoPublicClass **>(&_go_pptr) = 0;
}

GoPublicClass::GoPublicClass()
    : _go_pptr(new GoPrivateInfo())
{
    *const_cast<GoPublicClass **>(&_go_pptr->_go_pptr) = this;
}

GoPublicClass::~GoPublicClass()
{
    delete _go_pptr; *const_cast<GoPrivateInfo **>(&_go_pptr) = 0;
}

GoPublicClass::GoPublicClass(GoPrivateInfo &pi)
    : _go_pptr(&pi)
{
    *const_cast<GoPublicClass **>(&_go_pptr->_go_pptr) = this;
}
