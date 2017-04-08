#ifndef CAN_H
#define CAN_H

class CAN {
	public:
		CAN();
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
		void setFilters(uint32_t f0, uint32_t f1, uint32_t f2, uint32_t f3, uint32_t f4, uint32_t f5, uint32_t f6, uint32_t f7);
		bool busInitialized = false;
		CAN_message_t rxMsg;
	private:
		//FlexCAN canBus;
		CAN_filter_t filter0;
		CAN_filter_t filter1;
		CAN_filter_t filter2;
		CAN_filter_t filter3;
		CAN_filter_t filter4;
		CAN_filter_t filter5;
		CAN_filter_t filter6;
		CAN_filter_t filter7;
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