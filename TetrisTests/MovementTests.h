#pragma once

#include "Tetris.h"
#include "CUnit.h"
#include <stdint.h>

#define ASSERT_TETRIS_TABLES_EQUAL(aAaAa, bBbBb)	\
{													\
	for (int i = 0; i < TETRIS_TABLE_HEIGHT; ++i)	\
	{												\
		uint16_t x = aAaAa[i];						\
		uint16_t y = bBbBb[i];						\
		CU_ASSERT_EQUAL(x, y);						\
	}												\
}													\

inline void TestMovementLeftRight(void)
{
	Tetris_Game game;
	Tetris_ResetGame(&game, Tetris_GetUnit('O'));

	uint16_t expectedTable[TETRIS_TABLE_HEIGHT] = {
		0b0000000000000000,
		0b0000000011000000,
		0b0000000011000000,
		0b0000000000000000,
	};
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 8);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerLeft(&game);

	expectedTable[1] <<= 1;
	expectedTable[2] <<= 1;
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 7);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);

	expectedTable[1] <<= 2;
	expectedTable[2] <<= 2;
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 5);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerRight(&game);
	Tetris_MovePlayerRight(&game);
	Tetris_MovePlayerRight(&game);

	expectedTable[1] >>= 3;
	expectedTable[2] >>= 3;
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 8);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerRight(&game);

	expectedTable[1] >>= 1;
	expectedTable[2] >>= 1;
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 9);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerLeft(&game);

	expectedTable[1] <<= 1;
	expectedTable[2] <<= 1;
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 8);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	game.table[1] |= 0b0001000000010000;

	Tetris_MovePlayerRight(&game);

	expectedTable[1] = 0b0001000001110000;
	expectedTable[2] >>= 1;
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 9);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerRight(&game);

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 9);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerRight(&game);
	Tetris_MovePlayerRight(&game);
	Tetris_MovePlayerRight(&game);
	Tetris_MovePlayerRight(&game);
	Tetris_MovePlayerRight(&game);

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 9);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerLeft(&game);

	expectedTable[1] = 0b0001000011010000;
	expectedTable[2] <<= 1;
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 8);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerLeft(&game);

	expectedTable[1] = 0b0001000110010000;
	expectedTable[2] <<= 1;
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 7);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);

	expectedTable[1] = 0b0001110000010000;
	expectedTable[2] <<= 3;
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 4);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerLeft(&game);

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 4);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 4);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	game.table[1] = 0b0000110000010000;
	game.table[2] |= 0b0001000000000000;

	Tetris_MovePlayerLeft(&game);

	expectedTable[1] = 0b0000110000010000;
	expectedTable[2] = 0b0001110000000000;
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 4);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerRight(&game);
	Tetris_MovePlayerRight(&game);

	expectedTable[1] = 0b0000001100010000;
	expectedTable[2] = 0b0001001100000000;
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 6);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);

	expectedTable[1] = 0b0000110000010000;
	expectedTable[2] = 0b0001110000000000;
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 4);
	CU_ASSERT_EQUAL(game.player.position.y, 2);
}
