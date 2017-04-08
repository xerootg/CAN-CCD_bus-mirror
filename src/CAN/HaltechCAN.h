#include "CANBase.h"

class HaltechCAN: public CANBase {
	public:
		HaltechCAN();
	private:
		void busRecieve();
};