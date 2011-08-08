/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		socketconnection.cpp
*	@brief		SocketConnection class implementation
*	@author		Kamil Wiatrowski
*	@date		18-May-2011
*/

#include "socketconnection.h"
#include "address.h"
#include <sstream>

namespace osocket
{

const char* SocketConnection::CLASS_NAME = "SocketConnection";

/**
**  Method        SocketConnection::SocketConnection
**/
SocketConnection::SocketConnection()
: Socket()
{
}

/**
**  Method        SocketConnection::SocketConnection
**/
SocketConnection::SocketConnection(socktype socket_)
: Socket(socket_)
{
}

/**
**  Method        SocketConnection::SocketConnection
**/
SocketConnection::SocketConnection(socktype socket_, const Address& addr_)
: Socket(socket_), m_Address(addr_)
{
}

/**
**  Method        SocketConnection::SocketConnection
**/
SocketConnection::SocketConnection(const Address& addr_, const AddrInfoBase& hints_, SockFunctorContainer& functors_)
throw(SocketException)
: Socket(addr_, hints_, functors_)
{
}

/**
**  Method        SocketConnection::~SocketConnection
**/
SocketConnection::~SocketConnection()
{
}

/**
**  Method        SocketConnection::receive
**/
_Int SocketConnection::receive(_Char* buffer_, _Int bufflen_) throw(SocketException)
{
    _Int pos = ::recv(getSockDesc(), (sockraw*) buffer_, bufflen_, 0);

    if (pos < 0)
    {
        std::ostringstream oss;
        EX_LOG(oss, "receive") << gai_strerror(lasterror);
        throw SocketException(oss.str());
    }

    return pos;
}

/**
**  Method        SocketConnection::send
**/
_Int SocketConnection::send(const _Char* buffer_, _Int bufflen_) throw(SocketException)
{
    _Int pos = ::send(getSockDesc(), (sockraw*) buffer_, bufflen_, 0);

    if (pos < 0)
    {
        std::ostringstream oss;
        EX_LOG(oss, "send") << gai_strerror(lasterror);
        throw SocketException(oss.str());
    }

    return pos;
}

/**
**  Method        SocketConnection::sendAll
**/
_Int SocketConnection::sendAll(const _Char* buffer_, _Int bufflen_) throw(SocketException)
{
    _Int sendsofar = 0;
    _Int pos = 0;

    while (sendsofar < bufflen_)
    {
        pos = send(buffer_ + sendsofar, bufflen_ - sendsofar);
        if (pos == 0)
        {
            return sendsofar;
        }
        sendsofar += pos;
    }
    return sendsofar;
}

} // namespace osocket
