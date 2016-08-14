/*
ECU Simulator (CAN-CCD bus translator)
Copyright (C) 2016  Alexia E. Smith

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#define XJ_PLATFORM true

#include "include/CCD/CCD.h"
#include "include/CAN/HaltechCAN.h"

const boolean debug = true;

const int led = LED_BUILTIN;
HaltechCAN canBus;
CCD ccdBus;

float lastMPH = 0;
unsigned long lastMillis = 0;

void setup() {
	pinMode(led, OUTPUT);

	if (debug) {
		delay(1000);
		Serial.println(F("CAN-CCD Bus"));
	}

	ccdBus.init(Serial1);

	if (canBus.init()) {
		canBus.setMask(0x360 | 0x361 | 0x370 | 0x372 | 0x3E0 | 0x3E2 | 0x3E4);
		digitalWrite(led, HIGH);
	} else {
		digitalWrite(led, LOW);
	}

	ccdBus.setVoltage(14);
	ccdBus.setOilPSI(35);
	ccdBus.setFuelPercent(50);
	ccdBus.setCoolantTemperature(210);
	ccdBus.setAirBagLight(false);
	ccdBus.setCheckGaugesLight(false);
	ccdBus.setCheckEngineLight(false);
	ccdBus.setSKIMLight(false);
	ccdBus.setShiftLight(false);
	ccdBus.setCruiseLight(false);
	ccdBus.doUpdates();
	lastMillis = millis();
}

String dataIn;
char CR = 10;
float rpm = 2500;
byte bitfield = 0x00;
void loop() {
	/*byte inByte = (byte) Serial1.read();
	Serial.println(inByte, HEX);*/

	/*if (Serial.available() > 0) {
		dataIn = Serial.readStringUntil(CR);
		bitfield = dataIn.toInt();
		Serial.println(bitfield, HEX);
	}

	ccdBus.setRPM(rpm + random(0, 10));
	ccdBus.setMPH(55);
	ccdBus.setKPH(85.5);
	ccdBus.doUpdates();*/

	//delay(100);
	//ccdBus.busTransmit(FEATURE_STATUS_ID, 2, bitfield, bitfield);
	canBus.tick();
}