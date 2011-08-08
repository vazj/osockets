/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		winsockinit.h
*	@brief		WinSockInit class implementation
*	@author		Kamil Wiatrowski
*	@date		07-May-2011
*/


#include "winsockinit.h"
#ifdef _WINDOWS_

#include <sstream>

namespace osocket
{

/** @brief  static members initilisation */
WinSockInit* WinSockLoader::m_pWinSock = NULL;
_Int WinSockLoader::m_Counter = 0;
_SBool WinSockLoader::m_ManLoaded = false;


/**
**  Method        WinSockInit::WinSockInit
**/
WinSockInit::WinSockInit() throw(SocketException)
{
    _Int ret;
    // Load WinSock DLL, request v2.0
    ret = WSAStartup(MAKEWORD(2,0), &m_WsaData);
    if ( ret != 0 )
    {
        std::ostringstream oss;
        oss << "Failed to load WinSock DLL: " << gai_strerror(ret);
        throw SocketException(oss.str());
    }
}

/**
**  Method        WinSockInit::~WinSockInit
**/
WinSockInit::~WinSockInit()
{
    WSACleanup();
}

/**
**  Method        WinSockLoader::WinSockLoad
**/
void WinSockLoader::WinSockLoad() throw(SocketException)
{
    m_ManLoaded = true;
    if (m_pWinSock == NULL)
    {
        m_pWinSock = new WinSockInit();
    }
}

/**
**  Method        WinSockLoader::WinSockCleanUp
**/
void WinSockLoader::WinSockCleanUp()
{
    m_ManLoaded = false;
    if (m_Counter == 0 && m_pWinSock != NULL)
    {
        delete m_pWinSock;
        m_pWinSock = NULL;
    }
}

/**
**  Method        WinSockLoader::sockadd
**/
void WinSockLoader::sockadd() throw(SocketException)
{
    ++m_Counter;
    if (m_Counter == 1 && m_pWinSock == NULL)
    {
        m_pWinSock = new WinSockInit();
    }
}

/**
**  Method        WinSockLoader::sockremove
**/
void WinSockLoader::sockremove()
{
    --m_Counter;
    if (m_ManLoaded == false && m_Counter == 0 && m_pWinSock != NULL)
    {
        delete m_pWinSock;
        m_pWinSock = NULL;
    }
}

/**
**  Method        WinSockLoader::getWSADATA
**/
const WSADATA* WinSockLoader::getWSADATA()
{
    if (m_pWinSock == NULL)
    {
        return NULL;
    }

    return &(m_pWinSock->m_WsaData);
}

} // namespace osocket
#endif // _WINDOWS_

