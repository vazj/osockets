/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		addrinfo.cpp
*	@brief		AddrInfo class implementation
*	@author		Kamil Wiatrowski
*	@date		30-Apr-2011
*/

#include "imp/addrinfo.h"
#include <sstream>


namespace osocket
{

const char* AddrInfo::CLASS_NAME = "AddrInfo";

/**
**  Method        AddrInfo::AddrInfo
**/
AddrInfo::AddrInfo(const Address& target_, const AddrInfoBase& hints_) throw(SocketException)
{
    struct addrinfo hints;
    memset(&hints, 0, sizeof hints);

    hints.ai_family = hints_.getFamily();
    hints.ai_socktype = hints_.getSockType();
    hints.ai_flags = hints_.getFlags();
    hints.ai_protocol = hints_.getProtocol();

    _Int ret = getaddrinfo(target_.getNodename(),target_.getService(), &hints, &m_pAddrInfo);
    if ( ret != 0 )
    {
        std::ostringstream oss;
        EX_LOG(oss, "AddrInfo") << "getaddrinfo failed for " << target_.toString() << "; " <<
                                gai_strerror(ret);

        throw SocketException(oss.str());
    }

    m_pAddrRoot = m_pAddrInfo;
}

/**
**  Method        AddrInfo::~AddrInfo
**/
AddrInfo::~AddrInfo()
{
    freeaddrinfo(m_pAddrRoot);
}

/**
**  Method        AddrInfo::getFamily
**/
_Int AddrInfo::getFamily() const
{
    return m_pAddrInfo->ai_family;
}

/**
**  Method        AddrInfo::getSockType
**/
_Int AddrInfo::getSockType() const
{
    return m_pAddrInfo->ai_socktype;
}

/**
**  Method        AddrInfo::getFlags
**/
_Int AddrInfo::getFlags() const
{
    return m_pAddrInfo->ai_flags;
}

/**
**  Method        AddrInfo::getProtocol
**/
_Int AddrInfo::getProtocol() const
{
    return m_pAddrInfo->ai_protocol;
}

/**
**  Method        AddrInfo::getAddrLen
**/
socklen_t AddrInfo::getAddrLen() const
{
    return m_pAddrInfo->ai_addrlen;
}

/**
**  Method        AddrInfo::getSockAddr
**/
const struct sockaddr* AddrInfo::getSockAddr() const
{
    return m_pAddrInfo->ai_addr;
}

/**
**  Method        AddrInfo::getCanonName
**/
const _Char* AddrInfo::getCanonName() const
{
    return m_pAddrInfo->ai_canonname;
}

/**
**  Method        AddrInfo::empty
**/
_SBool AddrInfo::empty() const
{
    return (m_pAddrInfo == NULL);
}

/**
**  Method        AddrInfo::next
**/
AddrInfo* AddrInfo::next()
{
    m_pAddrInfo = m_pAddrInfo->ai_next;
    return this;
}

/**
**  Method        AddrInfo::begin
**/
void AddrInfo::begin()
{
    m_pAddrInfo = m_pAddrRoot;
}


/*AddrInfo::AddrInfo(const AddrInfo& other)
{
}

AddrInfo& AddrInfo::operator=(const AddrInfo& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}*/

} // namespace osocket

