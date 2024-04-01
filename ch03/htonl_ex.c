#include <stdint.h>
#include <netinet/in.h>

unit32_t htnol (uint32_t x)
{
    #if BYTE_ORDER == BIG_ENDIAN    //Big Endian인 경우, 원래의 값(x)를 그대로 리턴함
        return x;
    #elif BYTE_ORDER == LITTLE_ENDIAN
        return __bswap_323 (x);
    #else
    #error "What kind of system is this?"
    #endif
}