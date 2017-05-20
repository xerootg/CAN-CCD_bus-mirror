//Speed Multiplier
#ifdef XJ_SECGEN_PLATFORM
	#define SPEED_MULTIPLIER 1.59
#else
	#define SPEED_MULTIPLIER 1.6
#endif

//Fuel Capacity in Liters
#ifdef MJ_PLATFORM
	#define FUEL_CAPACITY 68.1374
#elif defined(XJ_FSTGEN_PLATFORM) || defined(XJ_SECGEN_PLATFORM)
	#define FUEL_CAPACITY 75.7082
#endif