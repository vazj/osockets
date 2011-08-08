/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		socketconnection.h
*	@brief		SocketConnection class definition
*	@author		Kamil Wiatrowski
*	@date		18-May-2011
*/

#ifndef SOCKETCONNECTION_H
#define SOCKETCONNECTION_H

#include "socket.h"

namespace osocket
{

/**
*	@brief		Socket to handle active connection
*/
class SocketConnection : public Socket
{
    public:
        /**
        *	@brief		Destructor
        */
        virtual ~SocketConnection();

        /**
        *	@brief		recieve data into buffer
        *   @param      buffer_        buffer to hold incoming data
        *   @param      bufflen_       size of buffer
        *   @return     size of received data
        *   @throw      SocketException if some error occured
        */
        _Int receive(_Char* buffer_, _Int bufflen_) throw(SocketException);

        /**
        *	@brief		send data to remote site
        *   @param      buffer_        buffer to hold data to send
        *   @param      bufflen_       size of buffer
        *   @return     size of data sent
        *   @throw      SocketException if some error occured
        */
        _Int send(const _Char* buffer_, _Int bufflen_) throw(SocketException);

        /**
        *	@brief		send all data from buffer to remote site
        *   @param      buffer_        buffer to hold data to send
        *   @param      bufflen_       size of buffer
        *   @return     size of data sent (should be equal to buffer size)
        *   @throw      SocketException if some error occured
        */
        _Int sendAll(const _Char* buffer_, _Int bufflen_) throw(SocketException);

        /**
        *	@brief		get address info
        *   @return     address info
        */
        inline const Address& getAddress() const { return m_Address; }
    protected:
        /**
        *	@brief		Default Constructor
        */
        SocketConnection();

        /**
        *	@brief		Constructor
        *   @param      socket_        socket descriptor
        */
        SocketConnection(socktype socket_);

        /**
        *	@brief		Constructor
        *   @param      socket_        socket descriptor
        *   @param      addr_          connection address
        */
        SocketConnection(socktype socket_, const Address& addr_);

        /**
        *	@brief		Constructor
        *   @param      addr_        connection address
        *   @param      hints_       hints for addrinfo
        *   @param      functors_    sequence of functors to create socket
        *   @throw      SocketException if failed to create new socket
        */
        SocketConnection(const Address& addr_, const AddrInfoBase& hints_, SockFunctorContainer& functors_) throw(SocketException);

        /**
        *	@brief		set address info
        *   @param      addr_        connection address
        */
        inline void setAddress(const Address& addr_) { m_Address = addr_; }

    private:
        /** @brief  address of remote site (ip and port) */
        Address m_Address;

        static const char* CLASS_NAME;

        friend class TCPServerSocket;
};

} // namespace osocket

#endif // SOCKETCONNECTION_H
