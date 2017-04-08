#include "CANBase.h"
#include <Arduino.h>
#include <Math.h>
#include <SPI.h>

CANBase::CANBase() {
	//MCP_CAN canBus(10);
}

/*
 * Initialize CAN bus and other necessary information.
 *
 * @access	public
 * @return	void
 */
float CANBase::init() {
	/*int speedIndex = this.canBus.connect();

	if (speedIndex != 255) {
		this.busInitialized = true;
		return true;
	}
	return false;*/
}

void CANBase::setMask(uint32_t idFilter) {
	/*CAN_filter_t filter;
	filter.id = idFilter;
	this.canBus.setMask(filter);*/
}

void CANBase::tick() {
	/*if (this.busInitialized && canBus.available()) {
		canBus.read(this.rxMsg);
		this.busRecieve();
	}*/
}

float CANBase::getRPM() {
	return rpm;
}

float CANBase::getMPH() {
	return mph;
}

float CANBase::getKPH() {
	return kph;
}

float CANBase::getOilPSI() {
	return oilPsi;
}

float CANBase::getVoltage() {
	return voltage;
}

float CANBase::getCoolantTemperature() {
	return coolantTemperature;
}

bool CANBase::getCheckEngineLight() {
	return checkEngineLight;
}

bool CANBase::getCheckGaugesLight() {
	return checkGaugesLight;
}