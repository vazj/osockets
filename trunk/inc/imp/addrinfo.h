/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		addrinfo.h
*	@brief		AddrInfo class definition
*	@author		Kamil Wiatrowski
*	@date		30-Apr-2011
*/

#ifndef ADDRINFO_H
#define ADDRINFO_H

#include "imp/osocketsdef.h"
#include "imp/addrinfobase.h"
#include "address.h"
#include "socketexception.h"


namespace osocket
{

/**
*	@brief		Wrapper for struct addrinfo
*/
class AddrInfo : public AddrInfoBaseIf
{
    public:
        /**
        *	@brief		Constructor
        *	@param		target_         address for which addrinfo should be obtained
        *   @param      hints_          hints for addrinfo
        */
        AddrInfo(const Address& target_, const AddrInfoBase& hints_) throw(SocketException);

        /**
        *	@brief		Destructor
        */
        virtual ~AddrInfo();

        /**
        *	@brief		get family
        *   @return     (e.g. AF_INET)
        */
        virtual _Int getFamily() const;

        /**
        *	@brief		get socket type
        *   @return     socktype (e.g. SOCK_STREAM)
        */
        virtual _Int getSockType() const;

        /**
        *	@brief		get flags
        *   @return     flags (e.g. AI_PASSIVE)
        */
        virtual _Int getFlags() const;

        /**
        *	@brief		get protocol
        *   @return     protocol (0 (auto) or IPPROTO_TCP, IPPROTO_UDP)
        */
        virtual _Int getProtocol() const;

        /**
        *	@brief		get sockaddr lenght
        *   @return     lenght of sockaddr
        */
        socklen_t getAddrLen() const;

        /**
        *	@brief		get canonname
        *   @return     canonname of host or NULL
        */
        const _Char* getCanonName() const;

        /**
        *	@brief		get sockaddr
        *   @return     pointer to sockaddr struct
        */
        const struct sockaddr* getSockAddr() const;

        /**
        *	@brief		check if addrinfo is filled
        *   @return     true if addrinfo is NULL and object can't be used
        */
        _SBool empty() const;

        /**
        *	@brief		move to next node of addrinfo
        *   @return     own pointer
        */
        AddrInfo* next();

        /**
        *	@brief		back to first node of addrinfo
        */
        void begin();

    protected:
    private:
        /**
        *	@brief		Copy constructor
        */
        AddrInfo(const AddrInfo& other_);
        /**
        *	@brief		Assignment operator
        */
        AddrInfo& operator=(const AddrInfo& rhs_);

        /** @brief  addrinfo with address info data */
        struct addrinfo *m_pAddrInfo;

        /** @brief  first addrinfo structure (needed for freeaddrinfo) */
        struct addrinfo *m_pAddrRoot;

        static const char* CLASS_NAME;
};

} // namespace osocket

#endif // ADDRINFO_H
