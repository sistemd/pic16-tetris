#include <xc.h>

#include "Compatibility.h"

#define _XTAL_FREQ 8000000

static inline void SetupOscillator(void)
{
    /* Make sure _XTAL_FREQ matches this configuration. */

    IRCF0 = 1;
    IRCF1 = 1;
    IRCF2 = 1;
}
