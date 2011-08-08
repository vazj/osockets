/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		hintstcpserver.h
*	@brief		HintsTCPServer class definition
*	@author		Kamil Wiatrowski
*	@date		02-May-2011
*/

#ifndef HINTSTCPSERVER_H
#define HINTSTCPSERVER_H

#include <imp/addrinfobase.h>

namespace osocket
{

/**
*	@brief		Hints appopriate for TCP Server
*/
class HintsTCPServer : public AddrInfoBase
{
    public:
        /**
        *	@brief		Constructor
        */
        HintsTCPServer();

        /**
        *	@brief		Destructor
        */
        virtual ~HintsTCPServer();
    protected:
    private:
};

} // namespace osocket

#endif // HINTSTCPSERVER_H
