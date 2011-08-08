/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		tcpsocket.h
*	@brief		TCPSocket class definition
*	@author		Kamil Wiatrowski
*	@date		18-July-2011
*/

#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include "socketconnection.h"

namespace osocket
{

/**
*	@brief		Socket working as TCP client
*/
class TCPSocket : public SocketConnection
{
    public:
        /**
        *	@brief		Constructor
        *   @param      addr_        remote server address (host and port)
        *   @throw      SocketException if connection failed
        */
        TCPSocket(const Address& addr_) throw(SocketException);

        /**
        *	@brief		Destructor
        */
        virtual ~TCPSocket();

    protected:
    private:
};

} // namespace osocket

#endif // TCPSOCKET_H
