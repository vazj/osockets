/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		hintsudp.cpp
*	@brief		HintsUDP class implementation
*	@author		Kamil Wiatrowski
*	@date		17-Aug-2011
*/

#include "imp/hintsudp.h"
#include "imp/osocketsdef.h"

namespace osocket
{

/**
**  Method        HintsUDP::HintsUDP
**/
HintsUDP::HintsUDP()
: AddrInfoBase(AF_UNSPEC, SOCK_DGRAM, 0, 0)
{
}

/**
**  Method        HintsUDP::~HintsUDP
**/
HintsUDP::~HintsUDP()
{
}

} // namespace osocket
