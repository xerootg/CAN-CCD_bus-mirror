#if defined(__AVR__)
#	warning Assuming HARD_SERIAL as Serial for an __AVR__.
#	define HARD_SERIAL Serial
#endif

#if defined(__NUC131_H__)
#	define CAN0_CS 10
#	define CAN0_INT 2
#endif 

#if defined(__ARMEL__)
#	if (defined(__MK20DX128__) || defined(__MK20DX256__)) && defined(CORE_TEENSY)
#		define HARD_SERIAL Serial1
#	else
#		warning Assuming HARD_SERIAL as Serial for an __ARMEL__.
#		define HARD_SERIAL Serial
#	endif
#endif