/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		winsockinit.h
*	@brief		WinSockInit class definition
*	@author		Kamil Wiatrowski
*	@date		07-May-2011
*/

#ifndef WINSOCKINIT_H
#define WINSOCKINIT_H

#include "imp/osocketsdef.h"
#ifdef _WINDOWS_

#include "socketexception.h"

namespace osocket
{

/**
*	@brief		Wraps loading of WinSock DLL, life cycle controled only by WinSockLoader class
*/
class WinSockInit
{
    public:
    protected:
    private:
        /**
        *	@brief		Constructor
        */
        WinSockInit() throw(SocketException);

        /**
        *	@brief		Destructor
        */
        ~WinSockInit();

        /** @brief  prevent value semantics */
        WinSockInit(const WinSockInit& other);
        WinSockInit& operator=(const WinSockInit& other);

        /** @brief  struct with WinSock info */
        WSADATA m_WsaData;

        friend class WinSockLoader;
};

/**
*	@brief		Loader utility for WinSock DLL
*/
class WinSockLoader
{
    public:
        /**
        *	@brief		Manualy load WinSock DLL, advisable to do it before any osocket usage
        */
        static void WinSockLoad() throw(SocketException);

        /**
        *	@brief		Manulay request for WinSock clean up, should be done any socket operations
        */
        static void WinSockCleanUp();

        /**
        *	@brief		get struct with WinSock info
        *   @return     pointer to WSADATA, NULL if WinSock DLL not loaded
        */
        static const WSADATA* getWSADATA();
    protected:

        /**
        *	@brief		Subscribe on every new socket creation
        */
        static void sockadd() throw(SocketException);

        /**
        *	@brief		Unsubscribe socket every time socket object is deleted
        */
        static void sockremove();

    private:
        /** @brief  WinSock loader */
        static WinSockInit *m_pWinSock;

        /** @brief  Counter with current number of socket objects */
        static _Int m_Counter;

        /** @brief  True if WinSock was manulay loaded by WinSockLoad() */
        static _SBool m_ManLoaded;

        friend class WinSock;
};

} // namespace osocket

#endif // _WINDOWS_
#endif // WINSOCKINIT_H
