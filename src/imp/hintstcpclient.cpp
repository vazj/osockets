/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		hintstcpclient.cpp
*	@brief		HintsTCPClient class implementation
*	@author		Kamil Wiatrowski
*	@date		30-Apr-2011
*/

#include "imp/hintstcpclient.h"
#include "imp/osocketsdef.h"


namespace osocket
{

/**
**  Method        HintsTCPClient::HintsTCPClient
**/
HintsTCPClient::HintsTCPClient()
: AddrInfoBase(AF_UNSPEC, SOCK_STREAM, 0, 0)
{
}

/**
**  Method        HintsTCPClient::~HintsTCPClient
**/
HintsTCPClient::~HintsTCPClient()
{
}

} // namespace osocket
