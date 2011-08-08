/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		addrinfobase.cpp
*	@brief		AddrInfoBase class implementation
*	@author		Kamil Wiatrowski
*	@date		30-Apr-2011
*/

#include "imp/addrinfobase.h"

namespace osocket
{

/**
**  Method        AddrInfoBase::AddrInfoBase
**/
AddrInfoBase::AddrInfoBase()
: m_Family(0), m_SockType(0), m_Flags(0), m_Protocol(0)
{
}

/**
**  Method        AddrInfoBase::AddrInfoBase
**/
AddrInfoBase::AddrInfoBase(_Int family_, _Int socktype_, _Int flags_, _Int protocol_)
: m_Family(family_), m_SockType(socktype_), m_Flags(flags_), m_Protocol(protocol_)
{
}

/**
**  Method        AddrInfoBase::~AddrInfoBase
**/
AddrInfoBase::~AddrInfoBase()
{
}

} // namespace osocket
