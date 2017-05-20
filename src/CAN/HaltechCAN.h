#ifndef HaltechCAN_H
#define HaltechCAN_H

#include "CANBase.h"

class HaltechCAN: public CANBase {
	public:
		HaltechCAN();
		bool frameHandler(CAN_message_t &frame, int mailbox, uint8_t controller);
};

#endif