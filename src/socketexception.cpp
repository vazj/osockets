/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		socketexception.cpp
*	@brief		Exception class for osockets.
*	@author		Kamil Wiatrowski
*	@date		26-Apr-2011
*/

#include "socketexception.h"

namespace osocket
{

/**
**  Method        SocketException::SocketException
**/
SocketException::SocketException( const std::string &description_ ) throw()
: m_sExceptionText(description_)
{
}

/**
**  Method        SocketException::~SocketException
**/
SocketException::~SocketException() throw()
{
}

/**
**  Method        SocketException::append
**/
void SocketException::append( const std::string &descriptionToAdd_ ) throw()
{
    m_sExceptionText.append("\n");
    m_sExceptionText.append(descriptionToAdd_);
}

/**
**  Method        SocketException::what
**/
const char* SocketException::what() const throw()
{
    return m_sExceptionText.c_str();
}

} // namespace osocket
