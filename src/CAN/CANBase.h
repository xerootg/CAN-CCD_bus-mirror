#ifndef CANBase_H
#define CANBase_H
#include "../Boards.h"
#include <mcp_can.h>

class CANBase {
	public:
		CANBase();
		float init();
		void setMask(uint32_t idFilter);
		void tick();
		float getRPM();
		float getMPH();
		float getKPH();
		float getOilPSI();
		float getVoltage();
		float getCoolantTemperature();
		bool getCheckEngineLight();
		bool getCheckGaugesLight();
		bool busInitialized = false;
	private:
		MCP_CAN canBus(CAN0_CS);
		float rpm = 0.0;
		float mph = 0.0;
		float kph = 0.0;
		float oilPsi = 0.0;
		float voltage = 0.0;
		float coolantTemperature = 0.0;
		bool checkEngineLight = false;
		bool checkGaugesLight = false;
		virtual void busRecieve() = 0;
};

#endif