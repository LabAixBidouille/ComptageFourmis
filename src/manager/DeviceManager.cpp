/*
 * DeviceManager.cpp
 *
 *  Created on: 30 oct. 2014
 *      Author: sebastien
 */

#include "DeviceManager.h"
#include <Arduino.h>
#include <Wire.h>

DeviceManager::DeviceManager() {
	Serial.print("Initializing RTC card...");
	Wire.begin();
	rtc.begin();
	Serial.println("RTC initialized.");
}

DeviceManager::~DeviceManager() {

}

void DeviceManager::update(unsigned long currentTime) {

}
