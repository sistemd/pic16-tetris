#pragma once

#include "CUnit.h"
#include "Digits.h"
#include <stdint.h>

inline void TestDigits(void)
{
    uint8_t digits[NUM_DIGITS];
    GetDigits(123, digits);

    for (int i = 0; i < NUM_DIGITS; ++i)
    {
        switch (i)
        {
        case NUM_DIGITS - 1:
            CU_ASSERT_EQUAL(digits[i], 3);
            break;
        case NUM_DIGITS - 2:
            CU_ASSERT_EQUAL(digits[i], 2);
            break;
        case NUM_DIGITS - 3:
            CU_ASSERT_EQUAL(digits[i], 1);
            break;
        default:
            CU_ASSERT_EQUAL(digits[i], 0);
            break;
        }
    }

    GetDigits(201, digits);

    for (int i = 0; i < NUM_DIGITS; ++i)
    {
        switch (i)
        {
        case NUM_DIGITS - 1:
            CU_ASSERT_EQUAL(digits[i], 1);
            break;
        case NUM_DIGITS - 3:
            CU_ASSERT_EQUAL(digits[i], 2);
            break;
        default:
            CU_ASSERT_EQUAL(digits[i], 0);
            break;
        }
    }

    GetDigits(9009, digits);

    for (int i = 0; i < NUM_DIGITS; ++i)
    {
        switch (i)
        {
        case NUM_DIGITS - 1:
            CU_ASSERT_EQUAL(digits[i], 9);
            break;
        case NUM_DIGITS - 4:
            CU_ASSERT_EQUAL(digits[i], 9);
            break;
        default:
            CU_ASSERT_EQUAL(digits[i], 0);
            break;
        }
    }

    GetDigits(12345, digits);

    for (int i = 0; i < NUM_DIGITS; ++i)
    {
        switch (i)
        {
        case NUM_DIGITS - 1:
            CU_ASSERT_EQUAL(digits[i], 5);
            break;
        case NUM_DIGITS - 2:
            CU_ASSERT_EQUAL(digits[i], 4);
            break;
        case NUM_DIGITS - 3:
            CU_ASSERT_EQUAL(digits[i], 3);
            break;
        case NUM_DIGITS - 4:
            CU_ASSERT_EQUAL(digits[i], 2);
            break;
        case NUM_DIGITS - 5:
            CU_ASSERT_EQUAL(digits[i], 1);
            break;
        default:
            CU_ASSERT_EQUAL(digits[i], 0);
            break;
        }
    }

    GetDigits(10305, digits);

    for (int i = 0; i < NUM_DIGITS; ++i)
    {
        switch (i)
        {
        case NUM_DIGITS - 1:
            CU_ASSERT_EQUAL(digits[i], 5);
            break;
        case NUM_DIGITS - 3:
            CU_ASSERT_EQUAL(digits[i], 3);
            break;
        case NUM_DIGITS - 5:
            CU_ASSERT_EQUAL(digits[i], 1);
            break;
        default:
            CU_ASSERT_EQUAL(digits[i], 0);
            break;
        }
    }
}
