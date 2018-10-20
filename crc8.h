#ifndef _crc8_h
#define _crc8_h


#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

typedef int                 BOOL;

BOOL  crc(unsigned char const msg[]);

#endif /* _crc8_h */
