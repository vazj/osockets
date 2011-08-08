/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		mutex.cpp
*	@brief		Mutex class implementation
*	@author		Kamil Wiatrowski
*	@date		06-May-2011
*/

#include "imp/mutex.h"


namespace osocket
{

/**
**  Method        Mutex::Mutex
**/
Mutex::Mutex()
{
#ifdef _WINDOWS_
    InitializeCriticalSection(&m_Mutex);
#else
    pthread_mutexattr_t at;
    _Int ret = pthread_mutexattr_init(&at);
    ret = pthread_mutexattr_settype(&at, PTHREAD_MUTEX_RECURSIVE);
    ret = pthread_mutex_init(&m_Mutex, &at);
#endif
}

/**
**  Method        Mutex::~Mutex
**/
Mutex::~Mutex()
{
#ifdef _WINDOWS_
    DeleteCriticalSection(&m_Mutex);
#else
    pthread_mutex_destroy(&m_Mutex);
#endif
}

/**
**  Method        Mutex::lock
**/
void Mutex::lock()
{
#ifdef _WINDOWS_
    EnterCriticalSection(&m_Mutex);
#else
    pthread_mutex_lock(&m_Mutex);
#endif
}

/**
**  Method        Mutex::unlock
**/
void Mutex::unlock()
{
#ifdef _WINDOWS_
    LeaveCriticalSection(&m_Mutex);
#else
    pthread_mutex_unlock(&m_Mutex);
#endif
}

/**
**  Method        Lock::Lock
**/
Lock::Lock(Mutex& mutex_)
: m_Mutex(mutex_)
{
    m_Mutex.lock();
}

/**
**  Method        Lock::~Lock
**/
Lock::~Lock()
{
    m_Mutex.unlock();
}

} // namespace osocket
