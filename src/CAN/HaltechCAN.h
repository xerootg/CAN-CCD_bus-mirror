#ifndef HaltechCAN_H
#define HaltechCAN_H

#include "CANBase.h"

class HaltechCAN: public CANBase {
	public:
		HaltechCAN();
	private:
		void busRecieve();
};

#endif