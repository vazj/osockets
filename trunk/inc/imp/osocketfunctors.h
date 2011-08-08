/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		osocketfunctors.h
*	@brief		Funtors for basic socket operations
*	@author		Kamil Wiatrowski
*	@date		11-May-2011
*/

#ifndef OSOCKETFUNCTORS_H
#define OSOCKETFUNCTORS_H

#include "imp/osocketsdef.h"
#include "imp/addrinfo.h"
#include <vector>

namespace osocket
{

/**
*	@brief		Interface for socket functors
*/
class SockFunctor
{
    public:
        SockFunctor() : m_errno(0) {}
        virtual ~SockFunctor() {};

        virtual _SBool operator() (socktype& sock_, const AddrInfo& ai_) = 0;
        virtual _Int getLastError() { return m_errno; }
    protected:
        void setErrno(_Int err_) { m_errno = err_; }
    private:
        _Int m_errno;
};

/**
*	@brief		Functor for creating socket
*/
class SocketFD : public SockFunctor
{
    public:
        virtual ~SocketFD() {};

        virtual _SBool operator() (socktype& sock_, const AddrInfo& ai_);
};

/**
*	@brief		Functor for binding socket
*/
class SockBind : public SockFunctor
{
    public:
        virtual ~SockBind() {};

        virtual _SBool operator() (socktype& sock_, const AddrInfo& ai_);
};

/**
*	@brief		Functor for connecting socket
*/
class SockConnect : public SockFunctor
{
    public:
        virtual ~SockConnect() {};

        virtual _SBool operator() (socktype& sock_, const AddrInfo& ai_);
};

/**
*	@brief		Functor for setting socket to reuse address
*/
class ReuseAddress : public SockFunctor
{
    public:
        virtual ~ReuseAddress() {};

        virtual _SBool operator() (socktype& sock_, const AddrInfo& ai_);
};


template<class T>
class TContainer : public std::vector<T>
{
    public:
        TContainer(T p1)
        {
            push_back(p1);
        }
        TContainer(T p1, T p2)
        {
            push_back(p1);
            push_back(p2);
        }
        TContainer(T p1, T p2, T p3)
        {
            push_back(p1);
            push_back(p2);
            push_back(p3);
        }
        TContainer(T p1, T p2, T p3, T p4)
        {
            push_back(p1);
            push_back(p2);
            push_back(p3);
            push_back(p4);
        }

        virtual ~TContainer() {}
    protected:
    private:
};

/** @brief  container with sockets functors */
typedef std::vector<SockFunctor*> SockFunctorContainer;

/** @brief  SockFunctors container, inherits SockFunctorContainer */
typedef TContainer<SockFunctor*> SockFunctors;

} // namespace osocket

#endif // OSOCKETFUNCTORS_H


