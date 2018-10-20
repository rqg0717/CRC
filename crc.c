#include "crc.h"

#define WIDTH   (8 * sizeof(crc))
#define TOPBIT  (1 << (WIDTH - 1))

static crc crcTable[256];

void  crcTableGen(void)
{
    crc remainder;

    // Perform binary long division, a bit at a time.
    for(int dividend = 0; dividend < 256; dividend++)
    {
        // Initialize the remainder. 
        remainder = dividend << (WIDTH - 8);
        // Shift and XOR with the polynomial.
        for(int bit = 0; bit < 8; bit++)
        {
            // Try to divide the current data bit.
            if(remainder & TOPBIT)
            {
                remainder = (remainder << 1) ^ POLYNOMIAL;
            }
            else
            {
                remainder = remainder << 1;
            }
        }
        //Save the result in the table.
        crcTable[dividend] = remainder;
    }
}

crc crcCompute(const unsigned char * msg, const unsigned int nBytes)
{
    unsigned char byte;
    crc remainder = INITIAL_REMAINDER;
    // Divide the message by the polynomial, a byte at a time.
    for(int offset = 0; offset < nBytes; offset++)
    {
        byte = (remainder >> (WIDTH - 8)) ^ message[offset];
        remainder = crcTable[byte] ^ (remainder << 8);
    }
    // The final remainder is the CRC.
    return (remainder ^ FINAL_XOR_VALUE);
}
