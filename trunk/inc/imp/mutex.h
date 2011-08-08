/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		mutex.h
*	@brief		Mutex class definition
*	@author		Kamil Wiatrowski
*	@date		06-May-2011
*/

#ifndef MUTEX_H
#define MUTEX_H

#include "imp/osocketsdef.h"
#ifdef _WINDOWS_
#include <windows.h>
#include <process.h>
#else
#include <pthread.h>
#endif

namespace osocket
{

/**
*	@brief		Class for mutual exclusion
*/
class Mutex
{
    public:
        /**
        *	@brief		Constructor
        */
        Mutex();

        /**
        *	@brief		Destructor
        */
        ~Mutex();

        /**
        *	@brief		lock mutex
        */
        void lock();

        /**
        *	@brief		unlock mutex
        */
        void unlock();

    protected:
    private:
    /** @brief  enviroment specific mutex object */
#ifdef _WINDOWS_
    CRITICAL_SECTION m_Mutex;
#else
    pthread_mutex_t m_Mutex;
#endif
};

/**
*	@brief		Class for scoped locking
*/
class Lock
{
    public:
        /**
        *	@brief		Constructor
        *   @param      mutex_        mutex object
        */
        Lock(Mutex& mutex_);

        /**
        *	@brief		Destructor
        */
        ~Lock();
    protected:
    private:
        /** @brief  mutex used for locking */
        Mutex m_Mutex;
};

} // namespace osocket

#endif // MUTEX_H
