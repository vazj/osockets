/************************************************************
*                          osockets
************************************************************/
/**
*	@file		osockettypes.h
*	@brief		typedefs for osockets.
*	@author		Kamil Wiatrowski
*	@date		22-Apr-2011
*/

#ifndef OSOCKETTYPES_H
#define OSOCKETTYPES_H

/** @brief lenght of string with biggest port number "65535" */
#define MAX_PORT_LEN 6
/** @brief lenght of string with longest possible host name */
#define MAX_HOSTNAME_LEN 255
/** @brief lenght of string with longest address */
#define MAX_ADDRSTRLEN INET6_ADDRSTRLEN

#define EX_LOG(outs, mth) (outs << __LINE__ << ":" << __FILE__ << "; in: " \
    << CLASS_NAME << "::" << mth << ": ")

namespace osocket
{
    typedef int _Int;
    typedef unsigned int _UInt;
    typedef char _Char;
    typedef unsigned char _UChar;
    typedef short _Short;
    typedef unsigned short _UShort;
    typedef bool _SBool;

} // namespace osocket


#endif // OSOCKETTYPES_H
