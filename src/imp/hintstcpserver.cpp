/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		hintstcpserver.cpp
*	@brief		HintsTCPServer class implementation
*	@author		Kamil Wiatrowski
*	@date		02-May-2011
*/

#include "imp/hintstcpserver.h"
#include "imp/osocketsdef.h"


namespace osocket
{

/**
**  Method        HintsTCPServer::HintsTCPServer
**/
HintsTCPServer::HintsTCPServer()
: AddrInfoBase(AF_UNSPEC, SOCK_STREAM, AI_PASSIVE, 0)
{
}

/**
**  Method        HintsTCPServer::HintsTCPServer
**/
HintsTCPServer::~HintsTCPServer()
{
}

} // namespace osocket
