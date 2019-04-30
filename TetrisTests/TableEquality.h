#pragma once

#include "CUnit.h"

#define ASSERT_TETRIS_TABLES_EQUAL(a, b) \
{ \
    for (int i = 0; i < TETRIS_TABLE_HEIGHT; ++i) \
    { \
        CU_ASSERT_EQUAL(a[i], b[i]); \
    } \
} \
