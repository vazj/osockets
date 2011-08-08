/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		osocketfunctors.cpp
*	@brief		Funtors implementation
*	@author		Kamil Wiatrowski
*	@date		11-May-2011
*/

#include "imp/osocketfunctors.h"

namespace osocket
{

/**
**  Method        SocketFD::operator()
**/
_SBool SocketFD::operator()(socktype& sock_, const AddrInfo& ai_)
{
    socktype tmp;
    tmp = ::socket(ai_.getFamily(), ai_.getSockType(), ai_.getProtocol());
    if (tmp == SOCK_INVALID)
    {
        setErrno(lasterror);
        return false;
    }

    sock_ = tmp;
    return true;
}

/**
**  Method        SockBind::operator()
**/
_SBool SockBind::operator()(socktype& sock_, const AddrInfo& ai_)
{
    if ( ::bind(sock_, ai_.getSockAddr(), ai_.getAddrLen()) == SOCK_ERROR )
    {
        setErrno(lasterror);
        return false;
    }
    return true;
}

/**
**  Method        SockConnect::operator()
**/
_SBool SockConnect::operator()(socktype& sock_, const AddrInfo& ai_)
{
    if ( ::connect(sock_, ai_.getSockAddr(), ai_.getAddrLen()) == SOCK_ERROR )
    {
        setErrno(lasterror);
        return false;
    }
    return true;
}

/**
**  Method        ReuseAddress::operator()
**/
_SBool ReuseAddress::operator()(socktype& sock_, const AddrInfo& ai_)
{
    _Int yes = 1;
    if ( ::setsockopt(sock_, SOL_SOCKET, SO_REUSEADDR, (sockraw*)&yes, sizeof(int)) == SOCK_ERROR )
    {
        setErrno(lasterror);
        return false;
    }
    return true;
}

} // namespace osocket


