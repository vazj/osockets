/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		tcpsocket.cpp
*	@brief		TCPSocket class implementation
*	@author		Kamil Wiatrowski
*	@date		18-July-2011
*/

#include "tcpsocket.h"
#include "imp/hintstcpclient.h"
#include "sockettoolbox.h"

namespace osocket
{

/**
**  Method        TCPSocket::TCPSocket
**/
TCPSocket::TCPSocket(const Address& addr_) throw(SocketException)
: SocketConnection()
{
    SocketFD sfd;
    SockConnect scn;
    SockFunctors sf(&sfd, &scn);

    setSocket(addr_, HintsTCPClient(), sf);

    setAddress( SocketToolbox::getPeerAddress(getSockDesc()) );
}

/**
**  Method        TCPSocket::~TCPSocket
**/
TCPSocket::~TCPSocket()
{
}

} // namespace osocket
