/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		tcpserversocket.cpp
*	@brief		TCPServerSocket class implementation
*	@author		Kamil Wiatrowski
*	@date		04-July-2011
*/

#include "tcpserversocket.h"
#include "socketconnection.h"
#include "imp/hintstcpserver.h"
#include <sstream>

namespace osocket
{

const char* TCPServerSocket::CLASS_NAME = "TCPServerSocket";

/**
**  Method        TCPServerSocket::TCPServerSocket
**/
TCPServerSocket::TCPServerSocket(const Address& addr_, _Int backlog_ /* = SOMAXCONN */) throw(SocketException)
: Socket()
{
    SocketFD sfd;
    ReuseAddress raddr;
    SockBind sb;
    SockFunctors sf(&sfd, &raddr, &sb);

    setSocket(addr_, HintsTCPServer(), sf);

    if ( ::listen(getSockDesc(), backlog_) == SOCK_ERROR )
    {
        std::ostringstream oss;
        EX_LOG(oss, "TCPServerSocket") << gai_strerror(lasterror);
        throw SocketException(oss.str());
    }
}

/**
**  Method        TCPServerSocket::~TCPServerSocket
**/
TCPServerSocket::~TCPServerSocket()
{
}

/**
**  Method        TCPServerSocket::accept
**/
SocketConnection* TCPServerSocket::accept() throw(SocketException)
{
    socktype foreignSocket; // socket for incoming connection
    struct sockaddr_storage foreignAddr; // container for foreing address
    socklen_t foreignAddrSize = sizeof(foreignAddr);

    foreignSocket = ::accept(getSockDesc(), (struct sockaddr *) &foreignAddr, &foreignAddrSize);
    if ( foreignSocket == SOCK_INVALID )
    {
        std::ostringstream oss;
        EX_LOG(oss, "accept") << gai_strerror(lasterror);
        throw SocketException(oss.str());
    }

    _Char saddr[MAX_ADDRSTRLEN];
    _UShort port;

    if ( inet_ntop_itl(foreignAddr.ss_family, getsinaddr((struct sockaddr*)&foreignAddr), saddr, sizeof(saddr)) == NULL )
    {
        closesock(foreignSocket);
        std::ostringstream oss;
        EX_LOG(oss, "accept") << "inet_ntop_itl failed to get foreign address";
        throw SocketException(oss.str());
    }
    port = ntohs( getsinport((struct sockaddr*)&foreignAddr) );

    SocketConnection *sc = new SocketConnection(foreignSocket, Address(saddr, port));

    return sc;
}

} // namespace osocket
