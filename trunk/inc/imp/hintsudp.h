/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		hintsudp.h
*	@brief		HintsUDP class definition
*	@author		Kamil Wiatrowski
*	@date		17-Aug-2011
*/

#ifndef HINTSUDP_H
#define HINTSUDP_H

#include <imp/addrinfobase.h>

namespace osocket
{

/**
*	@brief		Hints appopriate for UDP socket
*/
class HintsUDP : public AddrInfoBase
{
    public:
        /**
        *	@brief		Constructor
        */
        HintsUDP();

        /**
        *	@brief		Destructor
        */
        virtual ~HintsUDP();
    protected:
    private:
};

} // namespace osocket

#endif // HINTSUDP_H
