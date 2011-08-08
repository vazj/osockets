/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		socketexception.h
*	@brief		Exception class for osockets.
*	@author		Kamil Wiatrowski
*	@date		26-Apr-2011
*/

#ifndef SOCKETEXCEPTION_H
#define SOCKETEXCEPTION_H

#include <exception>
#include <string>

namespace osocket
{

/**
*	@brief		Socket Exception class
*/
class SocketException : public std::exception
{
    public:
        /**
        *	@brief		Constructor
        *	@param		description_		description of exception
        */
        SocketException( const std::string &description_ ) throw();

        /**
        *	@brief		Destructor
        */
        virtual ~SocketException() throw();

        /**
        *	@brief		Append additional description to exception
        *	@param		descriptionToAdd_		description to append
        */
        virtual void append( const std::string &descriptionToAdd_ ) throw();

        /**
        *	@brief		Get details about exception
        *	@return		string description of exception
        */
        virtual const char* what() const throw();

    protected:
    private:
        /** @brief  text description of exception */
        std::string m_sExceptionText;
};

} // namespace osocket

#endif // SOCKETEXCEPTION_H
