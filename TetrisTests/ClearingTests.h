#pragma once

#include "CUnit.h"
#include "Tetris.h"
#include "TableEquality.h"

inline void TestClearing(void)
{
    uint16_t tetrisTable[TETRIS_TABLE_HEIGHT] = {
        0b0000000000000000,
        0b1001000011111000,
        0b1111111111111111,
        0b0011100000001000,
    };

    uint16_t expectedTable[TETRIS_TABLE_HEIGHT] = {
        0b0000000000000000,
        0b0000000000000000,
        0b1001000011111000,
        0b0011100000001000,
    };

    CU_ASSERT_EQUAL(Tetris_ClearFilledRows(tetrisTable), 1);
    ASSERT_TETRIS_TABLES_EQUAL(tetrisTable, expectedTable);

    tetrisTable[0] = 0b0101010101010101;
    tetrisTable[1] = 0b1111111111111111;
    tetrisTable[2] = 0b1111111111111111;
    tetrisTable[3] = 0b0011100000001000;

    expectedTable[0] = 0b0000000000000000;
    expectedTable[1] = 0b0000000000000000;
    expectedTable[2] = 0b0101010101010101;
    expectedTable[3] = 0b0011100000001000;

    CU_ASSERT_EQUAL(Tetris_ClearFilledRows(tetrisTable), 2);
    ASSERT_TETRIS_TABLES_EQUAL(tetrisTable, expectedTable);

    tetrisTable[0] = 0b0000000000000000;
    tetrisTable[1] = 0b0000000000000000;
    tetrisTable[2] = 0b0000000000000000;
    tetrisTable[3] = 0b0000000000000000;

    expectedTable[0] = 0b0000000000000000;
    expectedTable[1] = 0b0000000000000000;
    expectedTable[2] = 0b0000000000000000;
    expectedTable[3] = 0b0000000000000000;

    CU_ASSERT_EQUAL(Tetris_ClearFilledRows(tetrisTable), 0);
    ASSERT_TETRIS_TABLES_EQUAL(tetrisTable, expectedTable);

    tetrisTable[3] = 0b0000000000000010;
    expectedTable[3] = 0b0000000000000010;

    CU_ASSERT_EQUAL(Tetris_ClearFilledRows(tetrisTable), 0);
    ASSERT_TETRIS_TABLES_EQUAL(tetrisTable, expectedTable);

    tetrisTable[0] = 0b0101010101010101;
    tetrisTable[1] = 0b1111111111111111;
    tetrisTable[2] = 0b1111111111111111;
    tetrisTable[3] = 0b0011100000001000;
    tetrisTable[4] = 0b1111111111111111;

    expectedTable[0] = 0b0000000000000000;
    expectedTable[1] = 0b0000000000000000;
    expectedTable[2] = 0b0000000000000000;
    expectedTable[3] = 0b0101010101010101;
    expectedTable[4] = 0b0011100000001000;

    CU_ASSERT_EQUAL(Tetris_ClearFilledRows(tetrisTable), 3);
    ASSERT_TETRIS_TABLES_EQUAL(tetrisTable, expectedTable);

    tetrisTable[0] = 0b0101010101010101;
    tetrisTable[1] = 0b1111111111111111;
    tetrisTable[2] = 0b1111111111111111;
    tetrisTable[3] = 0b1111111111111110;
    tetrisTable[4] = 0b1111111111111111;

    expectedTable[0] = 0b0000000000000000;
    expectedTable[1] = 0b0000000000000000;
    expectedTable[2] = 0b0000000000000000;
    expectedTable[3] = 0b0101010101010101;
    expectedTable[4] = 0b1111111111111110;

    CU_ASSERT_EQUAL(Tetris_ClearFilledRows(tetrisTable), 3);
    ASSERT_TETRIS_TABLES_EQUAL(tetrisTable, expectedTable);

    tetrisTable[0] = 0b1111111111111111;
    tetrisTable[1] = 0b0101010101010101;
    tetrisTable[2] = 0b1111111111111111;
    tetrisTable[3] = 0b1111111111111111;
    tetrisTable[4] = 0b1111111111111110;
    tetrisTable[5] = 0b1111111111111111;

    expectedTable[0] = 0b0000000000000000;
    expectedTable[1] = 0b0000000000000000;
    expectedTable[2] = 0b0000000000000000;
    expectedTable[3] = 0b0000000000000000;
    expectedTable[4] = 0b0101010101010101;
    expectedTable[5] = 0b1111111111111110;

    CU_ASSERT_EQUAL(Tetris_ClearFilledRows(tetrisTable), 4);
    ASSERT_TETRIS_TABLES_EQUAL(tetrisTable, expectedTable);
}
