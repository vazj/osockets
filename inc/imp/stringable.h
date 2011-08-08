/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		stringable.h
*	@brief		Stringable interface definition
*	@author		Kamil Wiatrowski
*	@date		30-Apr-2011
*/

#ifndef STRINGABLE_H
#define STRINGABLE_H

#include <string>
#include "imp/osockettypes.h"


namespace osocket
{

/**
*	@brief		Interface, declares method toString()
*/
class Stringable
{
    public:
        /**
        *	@brief		Constructor
        */
        Stringable() : m_bStrSet(false) {}

        /**
        *	@brief		Destructor
        */
        virtual ~Stringable() {}

        /**
        *	@brief		pure virtual method
        *   @return     object as string
        */
        virtual const _Char* toString() const = 0;
    protected:
        /** @brief  string representation of object */
        mutable std::string m_STRING;

        /** @brief  true if m_STRING was assigned */
        mutable _SBool m_bStrSet;
    private:
};

} // namespace osocket


#endif // STRINGABLE_H
