/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		socket.cpp
*	@brief		Socket class implementation
*	@author		Kamil Wiatrowski
*	@date		09-May-2011
*/

#include "socket.h"
#include "imp/addrinfo.h"
#include "address.h"
#include <sstream>

#ifdef _WINDOWS_
#include "winsockinit.h"

namespace osocket
{

/**
**  Method        WinSock::WinSock
**/
WinSock::WinSock()
{
    WinSockLoader::sockadd();
}

/**
**  Method        WinSock::~WinSock
**/
WinSock::~WinSock()
{
    WinSockLoader::sockremove();
}

}
#endif // _WINDOWS_

namespace osocket
{

const char* Socket::CLASS_NAME = "Socket";

/**
**  Method        Socket::Socket
**/
Socket::Socket()
: m_SockDesc(SOCK_INVALID)
{
}

/**
**  Method        Socket::Socket
**/
Socket::Socket(socktype socket_)
: m_SockDesc(socket_)
{
}

/**
**  Method        Socket::Socket
**/
Socket::Socket(const Address& addr_, const AddrInfoBase& hints_, SockFunctorContainer& functors_) throw(SocketException)
{
    try
    {
        setSocket(addr_, hints_, functors_);
    }
    catch (SocketException&)
    {
        throw;
    }
}

/**
**  Method        Socket::~Socket
**/
Socket::~Socket()
{
    if (m_SockDesc != SOCK_INVALID)
    {
        closesock(m_SockDesc);
    }
}

/**
**  Method        Socket::setSocket
**/
void Socket::setSocket(const Address& addr_, const AddrInfoBase& hints_, SockFunctorContainer& functors_) throw(SocketException)
{
    AddrInfo ai(addr_, hints_);

    std::ostringstream oss;
    socktype sockd;
    SockFunctors::iterator it;

    do
    {
        for (it = functors_.begin(); it != functors_.end(); ++it)
        {
            if ((**it)(sockd, ai) == false)
            {
                EX_LOG(oss, "setSocket") << gai_strerror((*it)->getLastError()) << "\n";
                break;
            }
        }
        if (it == functors_.end())
        {
            break;
        }
    } while ( !(ai.next()->empty()) );

    if (ai.empty())
    {
        oss << "Failed to create socket for " << addr_.toString();
        throw SocketException(oss.str());
    }

    m_SockDesc = sockd;
}



} // namespace osocket


