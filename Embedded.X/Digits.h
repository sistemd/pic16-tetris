#include <stdint.h>

#include "Compatibility.h"

/* XXX I don't like the name of this file */

typedef enum {
    NUM_DIGITS = 5,
} NumDigits;

inline void GetDigits(uint16_t n, uint8_t *digits)
{
    uint8_t i = NUM_DIGITS - 1;

    while (1)
    {
        uint16_t newN = n / 10;
        digits[i] = n - newN * 10;
        n = newN;

        if (i == 0)
            break;
        
        --i;
    }
}
