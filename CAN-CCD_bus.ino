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
#define XJ_SECGEN_PLATFORM true
#define MJ_PLATFORM true

//#include "src/Boards.h"
#include "src/CCD/CCD.h"
#include "src/CAN/HaltechCAN.h"

const boolean debug = true;

const int led = LED_BUILTIN;
HaltechCAN canBus;
CCD ccdBus;

float lastMPH = 0;
unsigned long lastMillis = 0;

void setup() {
	pinMode(led, OUTPUT);

	if (debug) {
		Serial.begin(9600);
		delay(1000);
		Serial.println(F("CAN-CCD Bus"));
	}

	Can0.begin(1000000);
	pinMode(2, OUTPUT);
	digitalWrite(2, HIGH);
	if (Can0.attachObj(&canBus)) {
		//canBus.setMask(0x360 | 0x361 | 0x370 | 0x372 | 0x3E0 | 0x3E2 | 0x3E4);
		canBus.attachGeneralHandler();
		digitalWrite(led, HIGH);
	} else {
		digitalWrite(led, LOW);
	}

	ccdBus.init(&Serial1);
	ccdBus.setAirBagLight(false);
	ccdBus.setSKIMLight(false);
	ccdBus.setShiftLight(false);
	ccdBus.setCruiseLight(false);
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
	}*/

	ccdBus.setVoltage(canBus.getVoltage());
	ccdBus.setOilPSI(canBus.getOilPSI());
	ccdBus.setFuelPercent(canBus.getFuelPercent());
	ccdBus.setCoolantTemperature(canBus.getCoolantTemperature());
	ccdBus.setCheckGaugesLight(canBus.getCheckGaugesLight());
	ccdBus.setCheckEngineLight(canBus.getCheckEngineLight());
	ccdBus.setRPM(canBus.getRPM());
	ccdBus.setMPH(canBus.getMPH());
	ccdBus.setKPH(canBus.getKPH());
	ccdBus.doUpdates();

	//ccdBus.busTransmit(FEATURE_STATUS_ID, 2, bitfield, bitfield);
}