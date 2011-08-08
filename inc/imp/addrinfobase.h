/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		addrinfobase.h
*	@brief		AddrInfoBase class definition
*	@author		Kamil Wiatrowski
*	@date		30-Apr-2011
*/

#ifndef ADDRINFOBASE_H
#define ADDRINFOBASE_H

#include <imp/addrinfobaseif.h>

namespace osocket
{

/**
*	@brief		Base class for Hints classes
*/
class AddrInfoBase : public AddrInfoBaseIf
{
    public:
        /**
        *	@brief		Constructor
        *	@param		family_		family (e.g. AF_INET)
        *   @param      socktype_   socket type (e.g. SOCK_STREAM)
        *   @param      flags_      flags (e.g. AI_PASSIVE)
        *   @param      protocol_   protocol (0 (auto) or IPPROTO_TCP, IPPROTO_UDP)
        */
        AddrInfoBase(_Int family_, _Int socktype_, _Int flags_, _Int protocol_);

        /**
        *	@brief		Destructor
        */
        virtual ~AddrInfoBase();

        /**
        *	@brief		get family
        *   @return     family (e.g. AF_INET)
        */
        inline virtual _Int getFamily() const { return m_Family; }

        /**
        *	@brief		get socket type
        *   @return     socktype (e.g. SOCK_STREAM)
        */
        inline virtual _Int getSockType() const { return m_SockType; }

        /**
        *	@brief		get flags
        *   @return     flags (e.g. AI_PASSIVE)
        */
        inline virtual _Int getFlags() const { return m_Flags; }

        /**
        *	@brief		get protocol
        *   @return     protocol (0 (auto) or IPPROTO_TCP, IPPROTO_UDP)
        */
        inline virtual _Int getProtocol() const { return m_Protocol; }

    protected:
        /**
        *	@brief		Constructor
        */
        AddrInfoBase();

    private:
        /** @brief  family */
        _Int m_Family;

        /** @brief  socket type */
        _Int m_SockType;

        /** @brief  flags */
        _Int m_Flags;

        /** @brief  protocol */
        _Int m_Protocol;
};

} // namespace osocket

#endif // ADDRINFOBASE_H
