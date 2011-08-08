/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		socket.h
*	@brief		Socket class definition
*	@author		Kamil Wiatrowski
*	@date		09-May-2011
*/

#ifndef SOCKET_H
#define SOCKET_H

#include "imp/osocketsdef.h"
#include "imp/osocketfunctors.h"
#include "socketexception.h"


namespace osocket
{

#ifdef _WINDOWS_
/**
*	@brief		Socket base class on windows only
*/
class WinSock
{
    public:
    protected:
        /**
        *	@brief		Constructor
        */
        WinSock();
        /**
        *	@brief		Destructor
        */
        virtual ~WinSock();
    private:
};
#endif

class Address;
class AddrInfoBase;

/**
*	@brief		Socket class, base for all types of sockets
*/
class Socket
#ifdef _WINDOWS_
    : private WinSock
#endif
{
    public:
        /**
        *	@brief		Destructor
        */
        virtual ~Socket();
    protected:
        /**
        *	@brief		Default Constructor
        */
        Socket();

        /**
        *	@brief		Constructor
        *   @param      socket_        socket descriptor
        */
        Socket(socktype socket_);

        /**
        *	@brief		Constructor
        *   @param      addr_        connection address
        *   @param      hints_       hints for addrinfo
        *   @param      functors_    sequence of functors to create socket
        *   @throw      SocketException if failed to create new socket
        */
        Socket(const Address& addr_, const AddrInfoBase& hints_, SockFunctorContainer& functors_) throw(SocketException);

        /**
        *	@brief		set new socket descriptor
        *   @param      addr_        connection address
        *   @param      hints_       hints for addrinfo
        *   @param      functors_    sequence of functors to create socket
        *   @throw      SocketException if failed to create new socket
        */
        void setSocket(const Address& addr_, const AddrInfoBase& hints_, SockFunctorContainer& functors_) throw(SocketException);

        /**
        *	@brief		set socket descritor
        *   @param      socket_      socket descriptor
        */
        inline void setSockDesc(socktype socket_) { m_SockDesc = socket_; }

        /**
        *	@brief		get socket descritor
        *   @return     socket descriptor
        */
        inline socktype getSockDesc() const { return m_SockDesc; }

    private:
        /** @brief  prevent value semantics */
        Socket(const Socket& other);
        Socket& operator=(const Socket& other);

        /** @brief  socket descriptor */
        socktype m_SockDesc;

        static const char* CLASS_NAME;
};

} // namespace osocket

#endif // SOCKET_H
