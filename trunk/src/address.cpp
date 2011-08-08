/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		address.cpp
*	@brief		Address class implementation
*	@author		Kamil Wiatrowski
*	@date		27-Apr-2011
*/

#include <stdio.h>
#include <sstream>

#include "address.h"
#include "sockettoolbox.h"


namespace osocket
{

const char* Address::CLASS_NAME = "Address";

/**
**  Method        Address::Address
**/
Address::Address()
: m_bHasNodename(false), m_sService("0"), m_Port(0),
    m_bHasPort(true)
{
}

/**
**  Method        Address::Address
**/
Address::Address(const _Char* nodename_, const _Char* service_)
: m_sNodename(nodename_), m_bHasNodename(true), m_sService(service_),
    m_bHasPort(false)
{
}

/**
**  Method        Address::Address
**/
Address::Address(const _Char* nodename_, const _UShort port_)
: m_sNodename(nodename_), m_bHasNodename(true), m_Port(port_),
    m_bHasPort(true)
{
    _Char portbuffer[MAX_PORT_LEN];
    snprintf(portbuffer, MAX_PORT_LEN, "%d", port_);

    // set service to port number
    m_sService.assign(portbuffer);
}

/**
**  Method        Address::Address
**/
Address::Address(const _Char* service_)
: m_bHasNodename(false), m_sService(service_), m_bHasPort(false)
{
}

/**
**  Method        Address::Address
**/
Address::Address(const _UShort port_)
: m_bHasNodename(false), m_Port(port_), m_bHasPort(true)
{
    _Char portbuffer[MAX_PORT_LEN];
    snprintf(portbuffer, MAX_PORT_LEN, "%d", port_);

    // set service to port number
    m_sService.assign(portbuffer);
}

/**
**  Method        Address::~Address
**/
Address::~Address()
{
}

/**
**  Method        Address::getNodename
**/
const _Char* Address::getNodename() const
{
    if (m_bHasNodename == true)
    {
        return m_sNodename.c_str();
    }
    return NULL;
}

/**
**  Method        Address::getService
**/
const _Char* Address::getService() const
{
    return m_sService.c_str();
}

/**
**  Method        Address::getPortNumber
**/
_UShort Address::getPortNumber() const
{
    if ( m_bHasPort )
    {
        return m_Port;
    }

    m_Port = SocketToolbox::getPortByServName(m_sService.c_str());
    m_bHasPort = true;

    return m_Port;
}

/**
**  Method        Address::toString
**/
const _Char* Address::toString() const
{
    if ( m_bStrSet )
    {
        return m_STRING.c_str();
    }

    m_STRING = "nodename[port]=";
    if (m_bHasNodename)
    {
        m_STRING += m_sNodename;
    }
    else
    {
        m_STRING += "NULL";
    }
    m_STRING += "[" + m_sService + "]";

    m_bStrSet = true;

    return m_STRING.c_str();
}

/*Address& Address::operator=(const Address& rhs_)
{
    if (this == &rhs_) return *this; // handle self assignment
    //assignment operator
    return *this;
}*/

} // namespace osocket
