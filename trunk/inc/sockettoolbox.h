/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		sockettoolbox.h
*	@brief		SocketToolbox class header
*	@author		Kamil Wiatrowski
*	@date		28-Apr-2011
*/

#ifndef SOCKETTOOLBOX_H
#define SOCKETTOOLBOX_H

#include "imp/osockettypes.h"
#include "imp/osocketsdef.h"
#include "socketexception.h"

namespace osocket
{

class Address;

/**
*	@brief		Helper methods for sockets
*/
class SocketToolbox
{
    public:
        /**
        *	@brief      get port number from string (service name or port)
        *	@param		service_		service
        *   @param      protocol_       protocol("tcp" or "udp"), default is NULL
        *   @return     port number for given service, 0 if corresponding number
        *               was not found
        *   @throw      SocketException in case service_ is null
        */
        static _UShort getPortByServName(const _Char* service_, const _Char* protocol_ = NULL) throw(SocketException);

        /**
        *	@brief      return Address info for given sock descriptor
        *	@param		sockdesc_		socket descriptor
        *   @return     address info (ip and port)
        *   @throw      SocketException if failed to get address info
        */
        static Address getPeerAddress(socktype sockdesc_) throw(SocketException);

        /**
        *	@brief      return own system name
        *	@param		name_           will hold the system name
        *   @return     true on success, otherwise false
        */
        static bool getSystemName(std::string& name_);

    protected:
    private:
        /**
        *	@brief		Private constructor to prevent instatiation
        */
        SocketToolbox();

        static const char* CLASS_NAME;
};

} // namespace osocket

#endif // SOCKETTOOLBOX_H
