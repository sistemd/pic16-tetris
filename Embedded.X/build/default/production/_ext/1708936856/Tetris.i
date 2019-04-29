# 1 "../Tetris/Tetris.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "../Tetris/Tetris.c" 2
# 1 "../Tetris/Tetris.h" 1


# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 1 3
# 13 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 3
typedef signed char int8_t;






typedef signed int int16_t;







typedef __int24 int24_t;







typedef signed long int int32_t;
# 52 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 3
typedef unsigned char uint8_t;





typedef unsigned int uint16_t;






typedef __uint24 uint24_t;






typedef unsigned long int uint32_t;
# 88 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 3
typedef signed char int_least8_t;







typedef signed int int_least16_t;
# 109 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 3
typedef __int24 int_least24_t;
# 118 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 3
typedef signed long int int_least32_t;
# 136 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 3
typedef unsigned char uint_least8_t;






typedef unsigned int uint_least16_t;
# 154 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 3
typedef __uint24 uint_least24_t;







typedef unsigned long int uint_least32_t;
# 181 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 3
typedef signed char int_fast8_t;






typedef signed int int_fast16_t;
# 200 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 3
typedef __int24 int_fast24_t;







typedef signed long int int_fast32_t;
# 224 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 3
typedef unsigned char uint_fast8_t;





typedef unsigned int uint_fast16_t;
# 240 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 3
typedef __uint24 uint_fast24_t;






typedef unsigned long int uint_fast32_t;
# 268 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 3
typedef int32_t intmax_t;
# 282 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 3
typedef uint32_t uintmax_t;






typedef int16_t intptr_t;




typedef uint16_t uintptr_t;
# 3 "../Tetris/Tetris.h" 2


enum
{
 TETRIS_MAX_ROTATIONS = 4,
};

typedef enum {
 TETRIS_TABLE_WIDTH = 16,
 TETRIS_TABLE_HEIGHT = 24,
} Tetris_TableSize;

typedef enum
{
 TETRIS_UNIT_HEIGHT = 4,
} Tetris_UnitSize;

typedef struct {
 uint8_t x;
 uint8_t y;
} Position;

typedef struct {
 char designator;
 uint8_t numRotations;
 uint16_t bits[TETRIS_UNIT_HEIGHT][TETRIS_MAX_ROTATIONS];
} Tetris_Unit;

typedef struct {
 Position position;
 const Tetris_Unit *unit;
 uint16_t unitBits[TETRIS_UNIT_HEIGHT];
 uint8_t rotation;
} Tetris_Player;





typedef struct {
 uint16_t table[TETRIS_TABLE_HEIGHT];
 Tetris_Player player;
 uint16_t currentScore;
} Tetris_Game;

typedef enum {
 TETRIS_GAME_OVER,
 TETRIS_GAME_CONTINUES,
} Tetris_GameState;

extern const Tetris_Unit *Tetris_GetRandomUnit(void);

extern const Tetris_Unit *Tetris_GetUnit(char designator);

extern void Tetris_ResetGame(Tetris_Game *game, const Tetris_Unit *playerUnit);

extern Tetris_GameState Tetris_UpdateGame(Tetris_Game *game);





extern uint8_t Tetris_ClearFilledRows(uint16_t *gameTable);

extern uint8_t Tetris_MovePlayerDown(Tetris_Game *game);

extern void Tetris_MovePlayerLeft(Tetris_Game *game);

extern void Tetris_MovePlayerRight(Tetris_Game *game);

extern void Tetris_RotatePlayer(Tetris_Game *game);
# 1 "../Tetris/Tetris.c" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdint.h" 1 3
# 2 "../Tetris/Tetris.c" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\string.h" 1 3





# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\__size_t.h" 1 3



typedef unsigned size_t;
# 6 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\string.h" 2 3

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\__null.h" 1 3
# 7 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\string.h" 2 3







extern void * memcpy(void *, const void *, size_t);
extern void * memmove(void *, const void *, size_t);
extern void * memset(void *, int, size_t);
# 36 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\string.h" 3
extern char * strcat(char *, const char *);
extern char * strcpy(char *, const char *);
extern char * strncat(char *, const char *, size_t);
extern char * strncpy(char *, const char *, size_t);
extern char * strdup(const char *);
extern char * strtok(char *, const char *);


extern int memcmp(const void *, const void *, size_t);
extern int strcmp(const char *, const char *);
extern int stricmp(const char *, const char *);
extern int strncmp(const char *, const char *, size_t);
extern int strnicmp(const char *, const char *, size_t);
extern void * memchr(const void *, int, size_t);
extern size_t strcspn(const char *, const char *);
extern char * strpbrk(const char *, const char *);
extern size_t strspn(const char *, const char *);
extern char * strstr(const char *, const char *);
extern char * stristr(const char *, const char *);
extern char * strerror(int);
extern size_t strlen(const char *);
extern char * strchr(const char *, int);
extern char * strichr(const char *, int);
extern char * strrchr(const char *, int);
extern char * strrichr(const char *, int);
# 3 "../Tetris/Tetris.c" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdlib.h" 1 3






typedef unsigned short wchar_t;







typedef struct {
 int rem;
 int quot;
} div_t;
typedef struct {
 unsigned rem;
 unsigned quot;
} udiv_t;
typedef struct {
 long quot;
 long rem;
} ldiv_t;
typedef struct {
 unsigned long quot;
 unsigned long rem;
} uldiv_t;
# 65 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdlib.h" 3
extern double atof(const char *);
extern double strtod(const char *, const char **);
extern int atoi(const char *);
extern unsigned xtoi(const char *);
extern long atol(const char *);



extern long strtol(const char *, char **, int);

extern int rand(void);
extern void srand(unsigned int);
extern void * calloc(size_t, size_t);
extern div_t div(int numer, int denom);
extern udiv_t udiv(unsigned numer, unsigned denom);
extern ldiv_t ldiv(long numer, long denom);
extern uldiv_t uldiv(unsigned long numer,unsigned long denom);



extern unsigned long _lrotl(unsigned long value, unsigned int shift);
extern unsigned long _lrotr(unsigned long value, unsigned int shift);
extern unsigned int _rotl(unsigned int value, unsigned int shift);
extern unsigned int _rotr(unsigned int value, unsigned int shift);




extern void * malloc(size_t);
extern void free(void *);
extern void * realloc(void *, size_t);




# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\xc8debug.h" 1 3
# 13 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\xc8debug.h" 3
#pragma intrinsic(__builtin_software_breakpoint)
extern void __builtin_software_breakpoint(void);
# 99 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c90\\stdlib.h" 2 3





extern int atexit(void (*)(void));
extern char * getenv(const char *);
extern char ** environ;
extern int system(char *);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
extern void * bsearch(const void *, void *, size_t, size_t, int(*)(const void *, const void *));
extern int abs(int);
extern long labs(long);

extern char * itoa(char * buf, int val, int base);
extern char * utoa(char * buf, unsigned val, int base);




extern char * ltoa(char * buf, long val, int base);
extern char * ultoa(char * buf, unsigned long val, int base);

extern char * ftoa(float f, int * status);
# 4 "../Tetris/Tetris.c" 2


enum
{
 TETRIS_NUM_UNITS = 7,
};

static Position const Tetris_unitPivot = {
 .x = 3,
 .y = 2,
};

static Position const Tetris_playerStartingPosition = {
 .x = 8,
 .y = 2,
};

static Tetris_Unit const Tetris_units[TETRIS_NUM_UNITS] = {
 {
  .designator = 'I',
  .numRotations = 2,
  .bits = {
   {
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
   },
   {
    0b00000000,
    0b00000000,
    0b00111100,
    0b00000000,
   },
  },
 },
 {
  .designator = 'O',
  .numRotations = 1,
  .bits = {
   {
    0b00000000,
    0b00011000,
    0b00011000,
    0b00000000,
   },
  },
 },
 {
  .designator = 'T',
  .numRotations = 4,
  .bits = {
   {
    0b00000000,
    0b00010000,
    0b00111000,
    0b00000000,
   },
   {
    0b00000000,
    0b00010000,
    0b00011000,
    0b00010000,
   },
   {
    0b00000000,
    0b00000000,
    0b00111000,
    0b00010000,
   },
   {
    0b00000000,
    0b00010000,
    0b00110000,
    0b00010000,
   },
  },
 },
 {
  .designator = 'L',
  .numRotations = 4,
  .bits = {
   {
    0b00000000,
    0b00010000,
    0b00010000,
    0b00011000,
   },
   {
    0b00000000,
    0b00001000,
    0b00111000,
    0b00000000,
   },
   {
    0b00000000,
    0b00110000,
    0b00010000,
    0b00010000,
   },
   {
    0b00000000,
    0b00000000,
    0b00111000,
    0b00100000,
   },
  },
 },
 {
  .designator = 'J',
  .numRotations = 4,
  .bits = {
   {
    0b00000000,
    0b00010000,
    0b00010000,
    0b00110000,
   },
   {
    0b00000000,
    0b00100000,
    0b00111000,
    0b00000000,
   },
   {
    0b00000000,
    0b00011000,
    0b00010000,
    0b00010000,
   },
   {
    0b00000000,
    0b00100000,
    0b00111000,
    0b00000000,
   },
  },
 },
 {
  .designator = 'S',
  .numRotations = 2,
  .bits = {
   {
    0b00000000,
    0b00011000,
    0b00110000,
    0b00000000,
   },
   {
    0b00000000,
    0b00010000,
    0b00011000,
    0b00001000,
   },
  },
 },
 {
  .designator = 'Z',
  .numRotations = 2,
  .bits = {
   {
    0b00000000,
    0b00110000,
    0b00011000,
    0b00000000,
   },
   {
    0b00000000,
    0b00001000,
    0b00011000,
    0b00010000,
   },
  },
 },
};

static uint8_t Tetris_PlayerTopmostY(Tetris_Player *player)
{
 return player->position.y - Tetris_unitPivot.y;
}

static uint8_t Tetris_PlayerOverlapsEnvironment(Tetris_Game *game)
{
 uint8_t start = Tetris_PlayerTopmostY(&game->player);
 for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
 {
  if (game->player.unitBits[i] & game->table[i + start])
   return 1;
 }

 return 0;
}

static uint8_t Tetris_PlayerTouchingLeftBound(Tetris_Player *player)
{
 for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
 {
  if (player->unitBits[i] & 0x8000)
   return 1;
 }

 return 0;
}

static uint8_t Tetris_PlayerTouchingRightBound(Tetris_Player *player)
{
 for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
 {
  if (player->unitBits[i] & 0x0001)
   return 1;
 }

 return 0;
}

static void Tetris_RemovePlayerFromTable(Tetris_Game *game)
{
 uint8_t start = Tetris_PlayerTopmostY(&game->player);
 for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
 {
  game->table[start + i] &= ~game->player.unitBits[i];
 }
}

static uint8_t Tetris_ApplyPlayerToTable(Tetris_Game *game)
{
 uint8_t start = Tetris_PlayerTopmostY(&game->player);

 for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
 {
  if (game->player.unitBits[i] == 0)
   continue;

  if (start + i >= TETRIS_TABLE_HEIGHT)
   return 0;
 }

 for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
  game->table[start + i] |= game->player.unitBits[i];

 return 1;
}

static uint8_t Tetris_CountUnitBits(const uint16_t *unitBits)
{
 uint8_t result = 0;
 for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
 {
  uint16_t mask = 1;
  for (uint8_t j = 0; j < TETRIS_TABLE_WIDTH; ++j)
  {
   if (unitBits[i] & mask)
    ++result;
   mask <<= 1;
  }
 }
 return result;
}

static void Tetris_UpdatePlayerUnitBits(Tetris_Player *player)
{
 for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
  player->unitBits[i] = player->unit->bits[player->rotation][i];

 int8_t shift = 8 - player->position.x + Tetris_unitPivot.x;

 if (shift > 0)
 {
  for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
   player->unitBits[i] <<= shift;
 }
 else
 {
  shift = -shift;
  for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
   player->unitBits[i] >>= shift;
 }
}

static uint8_t Tetris_PlayerUnitBitsAreValid(const Tetris_Player *player)
{
 return Tetris_CountUnitBits(player->unit->bits[player->rotation]) == Tetris_CountUnitBits(player->unitBits);
}

static void Tetris_SetPlayerUnit(Tetris_Player *player, const Tetris_Unit *unit)
{
 player->unit = unit;
 Tetris_UpdatePlayerUnitBits(player);
}

static void Tetris_ResetPlayer(Tetris_Player *player, const Tetris_Unit *playerUnit)
{
 player->position = Tetris_playerStartingPosition;
 player->rotation = 0;
 Tetris_SetPlayerUnit(player, playerUnit);
}

static void Tetris_ShiftTableDown(uint16_t *gameTable, uint8_t upto)
{
 uint8_t i;

 for (i = upto; i != 0; --i)
 {
  if (gameTable[i] == 0)
   break;
  gameTable[i] = gameTable[i - 1];
 }

 gameTable[i] = 0;
}

static uint8_t Tetris_ScoreForRowsCleared(uint8_t rowsCleared)
{
 switch (rowsCleared)
 {
 case 0: return 0;
 case 1: return 1;
 case 2: return 3;
 case 3: return 5;
 default: return 7;
 }
}

const Tetris_Unit *Tetris_GetRandomUnit(void)
{
 return Tetris_units + (rand() % TETRIS_NUM_UNITS);
}

const Tetris_Unit *Tetris_GetUnit(char designator)
{
 for (const Tetris_Unit *i = Tetris_units; i != Tetris_units + TETRIS_NUM_UNITS; ++i)
 {
  if (i->designator == designator)
   return i;
 }

 return (0);
}

void Tetris_ResetGame(Tetris_Game *game, const Tetris_Unit *playerUnit)
{
 memset(game, 0, sizeof *game);
 Tetris_ResetPlayer(&game->player, playerUnit);
 Tetris_ApplyPlayerToTable(game);
}

Tetris_GameState Tetris_UpdateGame(Tetris_Game *game)
{
 if (!Tetris_MovePlayerDown(game))
 {
  uint8_t rowsCleared = Tetris_ClearFilledRows(game->table);
  game->currentScore += Tetris_ScoreForRowsCleared(rowsCleared);

  Tetris_ResetPlayer(&game->player, Tetris_GetRandomUnit());
  if (Tetris_PlayerOverlapsEnvironment(game))
   return TETRIS_GAME_OVER;
  Tetris_ApplyPlayerToTable(game);
 }

 return TETRIS_GAME_CONTINUES;
}

uint8_t Tetris_ClearFilledRows(uint16_t *gameTable)
{
 uint8_t rowsCleared = 0;

 for (uint8_t i = 0; i < TETRIS_TABLE_HEIGHT;)
 {
  if (gameTable[i] == 0xFFFF)
  {
   Tetris_ShiftTableDown(gameTable, i);
   ++rowsCleared;
  }
  else
  {
   ++i;
  }
 }

 return rowsCleared;
}

uint8_t Tetris_MovePlayerDown(Tetris_Game *game)
{
 Tetris_RemovePlayerFromTable(game);
 ++game->player.position.y;

 if (Tetris_PlayerOverlapsEnvironment(game) || !Tetris_ApplyPlayerToTable(game))
 {
  --game->player.position.y;
  Tetris_ApplyPlayerToTable(game);
  return 0;
 }

 return 1;
}

void Tetris_MovePlayerLeft(Tetris_Game *game)
{
 if (Tetris_PlayerTouchingLeftBound(&game->player))
  return;

 Tetris_RemovePlayerFromTable(game);

 for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
  game->player.unitBits[i] <<= 1;

 if (Tetris_PlayerOverlapsEnvironment(game))
 {
  for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
   game->player.unitBits[i] >>= 1;
 }
 else
 {
  --game->player.position.x;
 }

 Tetris_ApplyPlayerToTable(game);
}

void Tetris_MovePlayerRight(Tetris_Game *game)
{
 if (Tetris_PlayerTouchingRightBound(&game->player))
  return;

 Tetris_RemovePlayerFromTable(game);

 for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
  game->player.unitBits[i] >>= 1;

 if (Tetris_PlayerOverlapsEnvironment(game))
 {
  for (uint8_t i = 0; i < TETRIS_UNIT_HEIGHT; ++i)
   game->player.unitBits[i] <<= 1;
 }
 else
 {
  ++game->player.position.x;
 }

 Tetris_ApplyPlayerToTable(game);
}

void Tetris_RotatePlayer(Tetris_Game *game)
{
 Tetris_RemovePlayerFromTable(game);

 uint8_t oldRotation = game->player.rotation;
 ++game->player.rotation;
 game->player.rotation %= game->player.unit->numRotations;
 Tetris_UpdatePlayerUnitBits(&game->player);
 if (!Tetris_PlayerUnitBitsAreValid(&game->player) || Tetris_PlayerOverlapsEnvironment(game))
 {
  game->player.rotation = oldRotation;
  Tetris_UpdatePlayerUnitBits(&game->player);
 }

 Tetris_ApplyPlayerToTable(game);
}
