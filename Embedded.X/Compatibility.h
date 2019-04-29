#ifdef DO_MAKE_COMPATIBLE

// So that VS Code doesn't give false errors

#undef inline
#define __interrupt()
#define __eeprom

#endif