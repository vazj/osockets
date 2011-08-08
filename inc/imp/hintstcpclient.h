/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		hintstcpclient.h
*	@brief		HintsTCPClient class definition
*	@author		Kamil Wiatrowski
*	@date		30-Apr-2011
*/

#ifndef HINTSTCPCLIENT_H
#define HINTSTCPCLIENT_H

#include <imp/addrinfobase.h>

namespace osocket
{

/**
*	@brief		Hints appopriate for TCP Client
*/
class HintsTCPClient : public AddrInfoBase
{
    public:
        /**
        *	@brief		Constructor
        */
        HintsTCPClient();

        /**
        *	@brief		Destructor
        */
        virtual ~HintsTCPClient();
    protected:
    private:
};

} // namespace osocket

#endif // HINTSTCPCLIENT_H
