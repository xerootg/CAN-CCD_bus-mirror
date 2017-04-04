#include "CAN.cpp"

class HaltechCAN: public CAN {
	public:
		HaltechCAN();
	private:
		void busRecieve();
};