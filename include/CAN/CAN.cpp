#include "CAN.h"
#include <Arduino.h>
#include <Math.h>

CAN::CAN() {

}

/*
 * Initialize CAN bus and other necessary information.
 *
 * @access	public
 * @return	void
 */
float CAN::init() {
	int speedIndex = this->canBus.begin();

	if (speedIndex != 255) {
		this->busInitialized = true;
		return true;
	}
	return false;
}

void CAN::setMask(uint32_t idFilter) {
    struct CAN_filter_t filter;
	filter.id = idFilter;
	this->canBus.setMask(filter);
}

void CAN::tick() {
	if (this->busInitialized && canBus.available()) {
		canBus.read(this->rxMsg);
		this->busRecieve();
	}
}

void CAN::setFilters(uint32_t f0, uint32_t f1, uint32_t f2, uint32_t f3, uint32_t f4, uint32_t f5, uint32_t f6, uint32_t f7) {
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

float CAN::getRPM() {
	return rpm;
}

float CAN::getMPH() {
	return mph;
}

float CAN::getKPH() {
	return kph;
}

float CAN::getOilPSI() {
	return oilPsi;
}

float CAN::getVoltage() {
	return voltage;
}

float CAN::getCoolantTemperature() {
	return coolantTemperature;
}

bool CAN::getCheckEngineLight() {
	return checkEngineLight;
}

bool CAN::getCheckGaugesLight() {
	return checkGaugesLight;
}