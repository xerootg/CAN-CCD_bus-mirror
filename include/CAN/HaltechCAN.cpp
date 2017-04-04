#include "HaltechCAN.h"
#include <Arduino.h>
#include <Math.h>

HaltechCAN::HaltechCAN() {

}

void HaltechCAN::busRecieve() {
	/*Serial.print("PID: ");
	Serial.print(this->rxMsg.id, HEX);
	Serial.print(" Data:");
	for (int x = 0; x < this->rxMsg.len; x ++) {
		Serial.print(" ");
		if (this->rxMsg.req == 0) {
			if (this->rxMsg.buf[x] < 10) {
				Serial.print("0");
			}
			Serial.print(this->rxMsg.buf[x], HEX);
		} else {
			Serial.print("00");
		}
	}
	Serial.print(" Request: ");
	Serial.print(this->rxMsg.req);
	Serial.print(" Timestamp: ");
	Serial.println(this->rxMsg.timestamp);*/
}