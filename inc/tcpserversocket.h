/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		tcpserversocket.h
*	@brief		TCPServerSocket class definition
*	@author		Kamil Wiatrowski
*	@date		04-July-2011
*/

#ifndef TCPSERVERSOCKET_H
#define TCPSERVERSOCKET_H

#include "socket.h"

namespace osocket
{

class SocketConnection;

/**
*	@brief		Socket working as TCP server
*/
class TCPServerSocket : public Socket
{
    public:
        /**
        *	@brief		Constructor
        *   @param      addr_        local server address (host and/or port)
        *   @param      backlog_     maximum number of concurrent connections per server
        *   @throw      SocketException if creating new TCP server failed
        */
        TCPServerSocket(const Address& addr_, _Int backlog_ = SOMAXCONN) throw(SocketException);

        /**
        *	@brief		Destructor
        */
        virtual ~TCPServerSocket();

        /**
        *	@brief		accept connection from remote site
        *   @return     return new connection, owner is responsible to delete pointer
        *   @throw      SocketException in case of any troubles
        */
        SocketConnection* accept() throw(SocketException);

    protected:
    private:
        static const char* CLASS_NAME;
};

} // namespace osocket

#endif // TCPSERVERSOCKET_H
