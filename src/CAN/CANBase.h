#ifndef CANBase_H
#define CANBase_H
#include <FlexCAN.h>

class CANBase : public CANListener {
	public:
		CANBase();
		void setMask(uint32_t idFilter);
		virtual bool frameHandler(CAN_message_t &frame, int mailbox, uint8_t controller);
		float getRPM();
		float getMPH();
		float getKPH();
		float getOilPSI();
		float getVoltage();
		float getFuelPercent();
		float getCoolantTemperature();
		bool getCheckEngineLight();
		bool getCheckGaugesLight();
		void setFilters(uint32_t f0, uint32_t f1, uint32_t f2, uint32_t f3, uint32_t f4, uint32_t f5, uint32_t f6, uint32_t f7);
		bool busInitialized = false;
		float rpm = 0.0;
		float mph = 0.0;
		float kph = 0.0;
		float oilPsi = 0.0;
		float voltage = 0.0;
		float fuelPercent = 0.0;
		float coolantTemperature = 0.0;
		float tps = 0.0;
		bool checkEngineLight = false;
		bool checkGaugesLight = false;
		CAN_message_t rxMsg;
	private:
		FlexCAN canBus;
		struct CAN_filter_t filter0;
		struct CAN_filter_t filter1;
		struct CAN_filter_t filter2;
		struct CAN_filter_t filter3;
		struct CAN_filter_t filter4;
		struct CAN_filter_t filter5;
		struct CAN_filter_t filter6;
		struct CAN_filter_t filter7;
};

#endif