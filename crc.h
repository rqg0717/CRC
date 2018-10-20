
#ifndef _crc_h
#define _crc_h

#define CRC16


#if defined(CRC_CCITT)

typedef unsigned short  crc;

//CRC-CCITT=X16+X12+X5+X0

#define POLYNOMIAL			  0x1021
#define INITIAL_REMAINDER	0xFFFF
#define FINAL_XOR_VALUE		0x0000

#elif defined(CRC16)

typedef unsigned short    crc;

//CRC16=X16+X15+X2+X0
#define POLYNOMIAL			  0x8005
#define INITIAL_REMAINDER	0x0000
#define FINAL_XOR_VALUE		0x0000

#elif defined(CRC32)

typedef unsigned long     crc;

//CRC32=X32+X26+X23+X22+X16+X12+X11+X10+X8+X7+X5+X4+X2+X1+X0
#define POLYNOMIAL			  0x04C11DB7
#define INITIAL_REMAINDER	0xFFFFFFFF
#define FINAL_XOR_VALUE		0xFFFFFFFF

#endif

void  crcTableGen(void);

crc crcCompute(const unsigned char * msg, const unsigned int nBytes);

#endif /* _crc_h */
