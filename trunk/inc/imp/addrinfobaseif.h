/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		addrinfobaseif.h
*	@brief		AddrInfoBaseIf interface definition
*	@author		Kamil Wiatrowski
*	@date		30-Apr-2011
*/

#ifndef ADDRINFOBASEIF_H
#define ADDRINFOBASEIF_H

#include "imp/osockettypes.h"

namespace osocket
{

/**
*	@brief		Interface, basic methods for any addrinfo class
*/
class AddrInfoBaseIf
{
    public:
        /**
        *	@brief		Destructor
        */
        virtual ~AddrInfoBaseIf() {}

        /**
        *	@brief		pure virtual method
        *   @return     family (e.g. AF_INET)
        */
        virtual _Int getFamily() const = 0;

        /**
        *	@brief		pure virtual method
        *   @return     socktype (e.g. SOCK_STREAM)
        */
        virtual _Int getSockType() const = 0;

        /**
        *	@brief		pure virtual method
        *   @return     flags (e.g. AI_PASSIVE)
        */
        virtual _Int getFlags() const = 0;

        /**
        *	@brief		pure virtual method
        *   @return     protocol (0 (auto) or IPPROTO_TCP, IPPROTO_UDP)
        */
        virtual _Int getProtocol() const = 0;
    protected:
    private:
};

} // namespace osocket


#endif // ADDRINFOBASEIF_H
