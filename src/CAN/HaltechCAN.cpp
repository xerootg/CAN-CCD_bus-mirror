#include "CANBase.h"
#include "HaltechCAN.h"
#include "HaltechCANCodes.h"
#include <Arduino.h>
#include <Math.h>

HaltechCAN::HaltechCAN() {

}

bool HaltechCAN::frameHandler(CAN_message_t &frame, int mailbox, uint8_t controller) {
	switch (frame.id) {
		case H_RPM_MANPSI_TPS_COOLPSI_ID:
			this->rpm = (frame.buf[0] << 8) | frame.buf[1];
			this->tps = ((frame.buf[4] << 8) | frame.buf[5]) / 10;
			break;
		case H_FUELPSI_OILPSI_DEMAND_WASTE_PSI_ID:
			this->oilPsi = (frame.buf[2] << 8) | frame.buf[3] / 10;
			break;
		case H_SPEED_GEAR_INTANG1_INTANG2_ID:
			this->kph = (frame.buf[0] << 8) | frame.buf[1] / 10;
			break;
		case H_VOLTS_TARGETBOOST_BAROPSI_ID:
			this->voltage = (frame.buf[0] << 8) | frame.buf[1] / 10;
			break;
		case H_COOLTEMP_AIRTEMP_FUELTEMP_OILTEMP_ID:
			this->coolantTemperature = (frame.buf[0] << 8) | frame.buf[1] / 10;
			break;
		case H_FUELLEVEL_ID:
			this->fuelPercent = (((frame.buf[0] << 8) | frame.buf[1] / 10) / 68) * 100;
			break;
		case H_SWITCHES_LIGHTS_ID:
			break;
	}
	Serial.print("PID: ");
	Serial.print(frame.id, HEX);
	Serial.print(" Data:");
    for (int x = 0; x < frame.len; x++) {
		Serial.print(frame.buf[x], HEX);
		Serial.write(' ');
	}
	Serial.print(" Timestamp: ");
	Serial.println(frame.timestamp);

	return true;
}