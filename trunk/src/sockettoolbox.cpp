/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		sockettoolbox.cpp
*	@brief		SocketToolbox class implementation
*	@author		Kamil Wiatrowski
*	@date		28-Apr-2011
*/

#include "sockettoolbox.h"
#include "imp/osocketsdef.h"
#include "address.h"

#include <sstream>

namespace osocket
{
const char* SocketToolbox::CLASS_NAME = "SocketToolbox";

/**
**  Method        SocketToolbox::getPortByServName
**/
_UShort SocketToolbox::getPortByServName(const _Char* service_, const _Char* protocol_ /* = NULL */) throw(SocketException)
{
    if ( service_ == NULL )
    {
        std::ostringstream oss;
        EX_LOG(oss, "getPortByServName") << "Input parameter service name is [NULL]";
        throw SocketException(oss.str());
    }

    struct servent *serv;
    serv = ::getservbyname(service_, protocol_);
    if ( serv != NULL )
    {
        return ntohs(serv->s_port);
    }

    _UShort port = (_UShort) atoi(service_);

    if ( strlen(service_) >= MAX_PORT_LEN )
    {
        port = 0;
    }

    return port;
}

/**
**  Method        SocketToolbox::getPeerAddress
**/
Address SocketToolbox::getPeerAddress(socktype sockdesc_) throw(SocketException)
{
    struct sockaddr_storage addr;
    socklen_t len = sizeof(addr);
    _Char saddr[MAX_ADDRSTRLEN];
    _UShort port;

    if (::getpeername(sockdesc_, (struct sockaddr*)&addr, &len) < 0)
    {
        std::ostringstream oss;
        EX_LOG(oss, "getPeerAddress") << gai_strerror(lasterror);
        throw SocketException(oss.str());
    }

    // get IP
    if ( inet_ntop_itl(addr.ss_family, getsinaddr((struct sockaddr*)&addr), saddr, sizeof(saddr)) == NULL )
    {
        std::ostringstream oss;
        EX_LOG(oss, "getPeerAddress") << "inet_ntop_itl failed to get peer address";
        throw SocketException(oss.str());
    }
    // get port
    port = ntohs( getsinport((struct sockaddr*)&addr) );


    return Address(saddr, port);
}

/**
**  Method        SocketToolbox::getSystemName
**/
bool SocketToolbox::getSystemName(std::string& name_)
{
    _Char hostname[MAX_HOSTNAME_LEN];

    if ( ::gethostname(hostname, sizeof(hostname)) == SOCK_ERROR )
    {
        return false;
    }

    name_.assign(hostname);
    return true;
}

} // namespace osocket



