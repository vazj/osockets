/************************************************************
*                          osockets
************************************************************/
/**
*	@file		osocketsdef.h
*	@brief		Basic definitions for osockets.
*	@author		Kamil Wiatrowski
*	@date		22-Apr-2011
*/

#ifndef OSOCKETSDEF_H
#define OSOCKETSDEF_H

#include "imp/osockettypes.h"

#ifdef _WIN32
#define _WINDOWS_
#endif

#ifdef _WINDOWS_
#define _WIN32_WINNT 0x501
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>  // inet_pton,ntoa
#include <netdb.h>
#include <errno.h>
#endif


#ifdef _WINDOWS_
#define closesock closesocket
#define SOCK_INVALID INVALID_SOCKET
#define SOCK_ERROR SOCKET_ERROR
#define lasterror WSAGetLastError()

/** @brief internal implementation of inet_ntop for windows */
const char *inet_ntop_itl(short af, const void *src, char *dst, socklen_t size);

/** @brief internal implementation of inet_pton for windows */
int inet_pton_itl(int af, const char *src, void *dst);

#else
#define closesock close
#define SOCK_INVALID -1
#define SOCK_ERROR -1
#define lasterror errno
#define inet_ntop_itl inet_ntop
#define inet_pton_itl inet_pton
#endif

namespace osocket
{
#ifdef _WINDOWS_
    /** @brief socket descriptor type */
    typedef SOCKET socktype;
    /** @brief raw socket type */
    typedef char sockraw;

#else
    /** @brief socket descriptor type */
    typedef int socktype;
    /** @brief raw socket type */
    typedef void sockraw;

#endif

    /**
    *	@brief	Get in_addr or in6_addr from sockaddr
    *	@param	saddr_				sockaddr pointer
    *	@return						pointer to struct in(6)_addr
    */
    void *getsinaddr(const struct sockaddr *saddr_);

    /**
    *	@brief	Get port in network format from sockaddr
    *	@param	saddr_				sockaddr pointer
    *	@return						port in net format
    */
    _UShort getsinport(const struct sockaddr *saddr_);
} // namespace osocket

#endif // OSOCKETSDEF_H
