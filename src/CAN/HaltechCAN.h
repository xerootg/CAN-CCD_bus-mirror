#include "CAN.h"

class HaltechCAN: public CAN {
	public:
		HaltechCAN();
	private:
		void busRecieve();
};