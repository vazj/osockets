/***********************************************************
*                          osockets
***********************************************************/
/**
*	@file		osocketsdef.cpp
*	@brief		Basic definitions for osockets.
*	@author		Kamil Wiatrowski
*	@date		22-Apr-2011
*/


#include "imp/osocketsdef.h"


#ifdef _WINDOWS_
/**
**  Function        inet_ntop_itl
**/
const char *inet_ntop_itl(short af, const void *src, char *dst, socklen_t size)
{
    int ret;
    if (af == AF_INET)
    {
        struct sockaddr_in saddr;
        memset(&saddr, 0, sizeof(saddr));
        saddr.sin_family = AF_INET;
        memcpy(&saddr.sin_addr, src, sizeof(struct in_addr));

        ret = getnameinfo((struct sockaddr *)&saddr, sizeof(struct sockaddr_in),
                    dst, size, NULL, 0, NI_NUMERICHOST);

        return (ret == 0)? dst : NULL;
    }
    else if (af == AF_INET6)
    {
        struct sockaddr_in6 saddr;
        memset(&saddr, 0, sizeof(saddr));
        saddr.sin6_family = AF_INET6;
        memcpy(&saddr.sin6_addr, src, sizeof(struct in_addr6));

        ret = getnameinfo((struct sockaddr *)&saddr, sizeof(struct sockaddr_in6),
                    dst, size, NULL, 0, NI_NUMERICHOST);

        return (ret == 0)? dst : NULL;
    }
    return NULL;
}

/**
**  Function        inet_pton_itl
**/
int inet_pton_itl(int af, const char *src, void *dst)
{
    struct addrinfo hints, *address, *addresssave;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = af;

    if (getaddrinfo(src, NULL, &hints, &address) != 0)
    {
        return -1;
    }

    addresssave = address;

    while (address)
    {
        memcpy(dst, address->ai_addr, address->ai_addrlen);
        address = address->ai_next;
    }

    freeaddrinfo(addresssave);
    return 0;
}
#endif // _WINDOWS_


namespace osocket
{
    /**
    **  Function        getsinaddr
    **/
    void *getsinaddr(const struct sockaddr *saddr_)
    {
        if (saddr_->sa_family == AF_INET)
        {
            return &(((struct sockaddr_in*)saddr_)->sin_addr);
        }
        return &(((struct sockaddr_in6*)saddr_)->sin6_addr);
    }

    /**
    **  Function        getsinport
    **/
    _UShort getsinport(const struct sockaddr *saddr_)
    {
        if (saddr_->sa_family == AF_INET)
        {
            return ((struct sockaddr_in*)saddr_)->sin_port;
        }
        return ((struct sockaddr_in6*)saddr_)->sin6_port;
    }
} // namespace osocket
