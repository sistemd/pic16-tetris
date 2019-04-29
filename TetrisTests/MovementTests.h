#pragma once

#include "Tetris.h"
#include "CUnit.h"
#include "TableEquality.h"
#include <stdint.h>
#include <string.h>

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

	Tetris_ResetGame(&game, Tetris_GetUnit('I'));

	expectedTable[0] = 0b0000000010000000;
	expectedTable[1] = 0b0000000010000000;
	expectedTable[2] = 0b0000000010000000;
	expectedTable[3] = 0b0000000010000000;
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 8);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	game.table[3] |= 0b0001000000000000;
	Tetris_MovePlayerLeft(&game);

	expectedTable[0] = 0b0000000100000000;
	expectedTable[1] = 0b0000000100000000;
	expectedTable[2] = 0b0000000100000000;
	expectedTable[3] = 0b0001000100000000;
	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 7);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);

	expectedTable[0] = 0b0000100000000000;
	expectedTable[1] = 0b0000100000000000;
	expectedTable[2] = 0b0000100000000000;
	expectedTable[3] = 0b0001100000000000;
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

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 4);
	CU_ASSERT_EQUAL(game.player.position.y, 2);
}

inline void TestMovementDown(void)
{
	Tetris_Game game;
	Tetris_ResetGame(&game, Tetris_GetUnit('O'));
	game.table[4] = 0b1100111111111111;

	uint16_t expectedTable[TETRIS_TABLE_HEIGHT] = {
		0b0000000000000000,
		0b0000000011000000,
		0b0000000011000000,
		0b0000000000000000,
		0b1100111111111111,
	};

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 8);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	CU_ASSERT(Tetris_MovePlayerDown(&game));

	expectedTable[3] = expectedTable[1];
	expectedTable[1] = 0;

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 8);
	CU_ASSERT_EQUAL(game.player.position.y, 3);

	CU_ASSERT(!Tetris_MovePlayerDown(&game));

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 8);
	CU_ASSERT_EQUAL(game.player.position.y, 3);

	CU_ASSERT(!Tetris_MovePlayerDown(&game));
	CU_ASSERT(!Tetris_MovePlayerDown(&game));
	CU_ASSERT(!Tetris_MovePlayerDown(&game));

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 8);
	CU_ASSERT_EQUAL(game.player.position.y, 3);

	Tetris_MovePlayerLeft(&game);

	expectedTable[2] = 0b0000000110000000;
	expectedTable[3] = 0b0000000110000000;

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 7);
	CU_ASSERT_EQUAL(game.player.position.y, 3);

	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);
	Tetris_MovePlayerLeft(&game);

	expectedTable[2] = 0b0011000000000000;
	expectedTable[3] = 0b0011000000000000;

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 2);
	CU_ASSERT_EQUAL(game.player.position.y, 3);

	CU_ASSERT(Tetris_MovePlayerDown(&game));

	expectedTable[2] = 0;
	expectedTable[4] = 0b1111111111111111;

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 2);
	CU_ASSERT_EQUAL(game.player.position.y, 4);

	CU_ASSERT(Tetris_MovePlayerDown(&game));

	expectedTable[3] = 0;
	expectedTable[5] = 0b0011000000000000;

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 2);
	CU_ASSERT_EQUAL(game.player.position.y, 5);

	CU_ASSERT(Tetris_MovePlayerDown(&game));

	expectedTable[4] = 0b1100111111111111;
	expectedTable[6] = 0b0011000000000000;

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 2);
	CU_ASSERT_EQUAL(game.player.position.y, 6);

	Tetris_ResetGame(&game, Tetris_GetUnit('I'));

	memset(expectedTable, 0, TETRIS_TABLE_HEIGHT * sizeof *expectedTable);

	expectedTable[0] = 0b0000000010000000;
	expectedTable[1] = 0b0000000010000000;
	expectedTable[2] = 0b0000000010000000;
	expectedTable[3] = 0b0000000010000000;

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 8);
	CU_ASSERT_EQUAL(game.player.position.y, 2);

	CU_ASSERT(Tetris_MovePlayerDown(&game));

	expectedTable[0] = 0b0000000000000000;
	expectedTable[1] = 0b0000000010000000;
	expectedTable[2] = 0b0000000010000000;
	expectedTable[3] = 0b0000000010000000;
	expectedTable[4] = 0b0000000010000000;

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 8);
	CU_ASSERT_EQUAL(game.player.position.y, 3);

	int drop = TETRIS_TABLE_HEIGHT - game.player.position.y - 2;
	for (int i = 0; i < 20; ++i)
		CU_ASSERT(Tetris_MovePlayerDown(&game));

	memset(expectedTable, 0, TETRIS_TABLE_HEIGHT * sizeof *expectedTable);

	expectedTable[TETRIS_TABLE_HEIGHT - 4] = 0b0000000010000000;
	expectedTable[TETRIS_TABLE_HEIGHT - 3] = 0b0000000010000000;
	expectedTable[TETRIS_TABLE_HEIGHT - 2] = 0b0000000010000000;
	expectedTable[TETRIS_TABLE_HEIGHT - 1] = 0b0000000010000000;

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 8);
	CU_ASSERT_EQUAL(game.player.position.y, TETRIS_TABLE_HEIGHT - 2);

	CU_ASSERT(!Tetris_MovePlayerDown(&game));

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 8);
	CU_ASSERT_EQUAL(game.player.position.y, TETRIS_TABLE_HEIGHT - 2);

	CU_ASSERT(!Tetris_MovePlayerDown(&game));

	ASSERT_TETRIS_TABLES_EQUAL(game.table, expectedTable);
	CU_ASSERT_EQUAL(game.player.position.x, 8);
	CU_ASSERT_EQUAL(game.player.position.y, TETRIS_TABLE_HEIGHT - 2);
}
