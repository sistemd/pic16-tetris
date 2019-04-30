#pragma once

#include "Tetris.h"
#include "TableEquality.h"

inline void TestRotation(void)
{
    Tetris_Game game;
    Tetris_ResetGame(&game, Tetris_GetUnit('T'));

    uint16_t expectedTable[TETRIS_TABLE_HEIGHT] = {
        0b0000000000000000,
        0b0000000010000000,
        0b0000000111000000,
        0b0000000000000000,
    };
    ASSERT_TETRIS_TABLES_EQUAL(expectedTable, game.table);
    CU_ASSERT_EQUAL(game.player.position.x, 8);
    CU_ASSERT_EQUAL(game.player.position.y, 2);

    Tetris_RotatePlayer(&game);
    expectedTable[1] = 0b0000000010000000;
    expectedTable[2] = 0b0000000011000000;
    expectedTable[3] = 0b0000000010000000;
    ASSERT_TETRIS_TABLES_EQUAL(expectedTable, game.table);
    CU_ASSERT_EQUAL(game.player.position.x, 8);
    CU_ASSERT_EQUAL(game.player.position.y, 2);

    Tetris_RotatePlayer(&game);
    expectedTable[1] = 0b0000000000000000;
    expectedTable[2] = 0b0000000111000000;
    expectedTable[3] = 0b0000000010000000;
    ASSERT_TETRIS_TABLES_EQUAL(expectedTable, game.table);
    CU_ASSERT_EQUAL(game.player.position.x, 8);
    CU_ASSERT_EQUAL(game.player.position.y, 2);

    Tetris_RotatePlayer(&game);
    Tetris_RotatePlayer(&game);
    expectedTable[1] = 0b0000000010000000;
    expectedTable[2] = 0b0000000111000000;
    expectedTable[3] = 0b0000000000000000;
    ASSERT_TETRIS_TABLES_EQUAL(expectedTable, game.table);
    CU_ASSERT_EQUAL(game.player.position.x, 8);
    CU_ASSERT_EQUAL(game.player.position.y, 2);

    game.table[3] = 0b0000000010000000;
    expectedTable[3] = game.table[3];

    Tetris_RotatePlayer(&game);
    ASSERT_TETRIS_TABLES_EQUAL(expectedTable, game.table);
    CU_ASSERT_EQUAL(game.player.position.x, 8);
    CU_ASSERT_EQUAL(game.player.position.y, 2);

    Tetris_RotatePlayer(&game);
    Tetris_RotatePlayer(&game);
    Tetris_RotatePlayer(&game);
    ASSERT_TETRIS_TABLES_EQUAL(expectedTable, game.table);
    CU_ASSERT_EQUAL(game.player.position.x, 8);
    CU_ASSERT_EQUAL(game.player.position.y, 2);

    Tetris_ResetGame(&game, Tetris_GetUnit('I'));
    expectedTable[0] = 0b0000000010000000;
    expectedTable[1] = 0b0000000010000000;
    expectedTable[2] = 0b0000000010000000;
    expectedTable[3] = 0b0000000010000000;

    ASSERT_TETRIS_TABLES_EQUAL(expectedTable, game.table);
    CU_ASSERT_EQUAL(game.player.position.x, 8);
    CU_ASSERT_EQUAL(game.player.position.y, 2);

    Tetris_RotatePlayer(&game);

    expectedTable[0] = 0b0000000000000000;
    expectedTable[1] = 0b0000000000000000;
    expectedTable[2] = 0b0000000111100000;
    expectedTable[3] = 0b0000000000000000;
    ASSERT_TETRIS_TABLES_EQUAL(expectedTable, game.table);
    CU_ASSERT_EQUAL(game.player.position.x, 8);
    CU_ASSERT_EQUAL(game.player.position.y, 2);

    game.table[1] = 0b1111111111111111;
    expectedTable[1] = game.table[1];

    Tetris_RotatePlayer(&game);

    ASSERT_TETRIS_TABLES_EQUAL(expectedTable, game.table);
    CU_ASSERT_EQUAL(game.player.position.x, 8);
    CU_ASSERT_EQUAL(game.player.position.y, 2);

    Tetris_RotatePlayer(&game);
    Tetris_RotatePlayer(&game);
    Tetris_RotatePlayer(&game);

    ASSERT_TETRIS_TABLES_EQUAL(expectedTable, game.table);
    CU_ASSERT_EQUAL(game.player.position.x, 8);
    CU_ASSERT_EQUAL(game.player.position.y, 2);

    game.table[0] = game.table[1];
    expectedTable[0] = expectedTable[1];
    game.table[1] = 0;
    expectedTable[1] = 0;

    ASSERT_TETRIS_TABLES_EQUAL(expectedTable, game.table);
    CU_ASSERT_EQUAL(game.player.position.x, 8);
    CU_ASSERT_EQUAL(game.player.position.y, 2);

    Tetris_RotatePlayer(&game);

    ASSERT_TETRIS_TABLES_EQUAL(expectedTable, game.table);
    CU_ASSERT_EQUAL(game.player.position.x, 8);
    CU_ASSERT_EQUAL(game.player.position.y, 2);

    Tetris_RotatePlayer(&game);
    Tetris_RotatePlayer(&game);
    Tetris_RotatePlayer(&game);

    ASSERT_TETRIS_TABLES_EQUAL(expectedTable, game.table);
    CU_ASSERT_EQUAL(game.player.position.x, 8);
    CU_ASSERT_EQUAL(game.player.position.y, 2);
}
