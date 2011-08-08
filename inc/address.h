/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		address.h
*	@brief		Address class definition
*	@author		Kamil Wiatrowski
*	@date		27-Apr-2011
*/

#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include "imp/stringable.h"
#include "imp/osockettypes.h"
//#include "socketexception.h"

namespace osocket
{

/**
*	@brief		Class bounding nodename and service(port) together
*/
class Address : public Stringable
{
    public:
        /**
        *	@brief		Default Constructor
        */
        Address();

        /**
        *	@brief		Constructor
        *	@param		nodename_		ip or hostname
        *   @param      service_        port or service name
        */
        Address(const _Char* nodename_, const _Char* service_);

        /**
        *	@brief		Constructor
        *	@param		nodename_		ip or hostname
        *   @param      service_        port
        */
        Address(const _Char* nodename_, const _UShort port_);

        /**
        *	@brief		Constructor
        *   @param      service_        port or service name
        */
        Address(const _Char* service_);

        /**
        *	@brief		Constructor
        *   @param      service_        port
        */
        Address(const _UShort port_);

        /**
        *	@brief		Destructor
        */
        virtual ~Address();

        //Address(const Address& other_);
        //Address& operator=(const Address& rhs_);

        /**
        *	@brief		get nodename (ip or hostname)
        *   @return     ip or hostname, NULL if not set
        */
        const _Char* getNodename() const;

        /**
        *	@brief		get service (port or name e.g. http or 80)
        *   @return     port or service name
        */
        const _Char* getService() const;

        /**
        *	@brief		get port number corresponding with service name
        *   @return     port number, 0 for unknown service
        */
        _UShort getPortNumber() const;

        /**
        *	@brief		return string description of object (node and service)
        *   @return     string description
        */
        virtual const _Char* toString() const;

    protected:
    private:
        /** @brief  ip or hostname */
        std::string m_sNodename;

        /** @brief  true if Nodename is set */
        _SBool m_bHasNodename;

        /** @brief  service name or port in string format */
        std::string m_sService;

        /** @brief  port */
        mutable _UShort m_Port;

        /** @brief  true if port number is set */
        mutable _SBool m_bHasPort;

        static const char* CLASS_NAME;
};

} // namespace osocket

#endif // ADDRESS_H
