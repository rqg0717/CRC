#ifndef _crc8_h
#define _crc8_h


#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

typedef unsigned char       BYTE;

BYTE crc(BYTE const msg[], int nBytes);

#endif /* _crc8_h */
