#include "CANBase.h"
#include <Arduino.h>
#include <Math.h>
#include <SPI.h>
#include <FlexCAN.h>

CANBase::CANBase() {

}

/*
 * Initialize CAN bus and other necessary information.
 *
 * @access	public
 * @return	void
 */
float CANBase::init() {
	int speedIndex = this->canBus.begin();

	if (speedIndex != 255) {
		this->busInitialized = true;
		this->canBus.setListenOnly(true);
		return true;
	}
	return false;
}

void CANBase::setMask(uint32_t idFilter) {
	CAN_filter_t filter;
	filter.id = idFilter;
	this->canBus.setMask(filter);
}

void CANBase::tick() {
	if (this->busInitialized && this->canBus.available()) {
		this->canBus.read(this->rxMsg);
		this->busRecieve();
	}
}

void CANBase::setFilters(uint32_t f0, uint32_t f1, uint32_t f2, uint32_t f3, uint32_t f4, uint32_t f5, uint32_t f6, uint32_t f7) {
	this->filter0.id = f0;
	this->filter0.ext = f0;
	this->canBus.setFilter(this->filter0, 0);

	this->filter1.id = f1;
	this->filter1.ext = f1;
	this->canBus.setFilter(this->filter1, 1);

	this->filter2.id = f2;
	this->filter2.ext = f2;
	this->canBus.setFilter(this->filter2, 2);

	this->filter3.id = f3;
	this->filter3.ext = f3;
	this->canBus.setFilter(this->filter3, 3);

	this->filter4.id = f4;
	this->filter4.ext = f4;
	this->canBus.setFilter(this->filter4, 4);

	this->filter5.id = f5;
	this->filter5.ext = f5;
	this->canBus.setFilter(this->filter5, 5);

	this->filter6.id = f6;
	this->filter6.ext = f6;
	this->canBus.setFilter(this->filter6, 6);

	this->filter7.id = f7;
	this->filter7.ext = f7;
	this->canBus.setFilter(this->filter7, 7);
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

float CANBase::getFuelPercent() {
	return fuelPercent;
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