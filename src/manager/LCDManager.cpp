#include <Arduino.h>
#include "LCDManager.h"
#include "DeviceManager.h"

LCDManager::LCDManager() :
		 lcd(0),lastChangeTime(0UL), refreshDelay(DEFAULT_REFRESH_DELAY), doorsData(10) {
	lastChangeTime = millis();
}

void LCDManager::refreshDisplay() {
	Serial.println("refresh LCD!!!");
	writeDateTime(DeviceManager::getInstance()->getDateTime());
	lcd->setCursor(0, 0);
	for(size_t i = 0; i < doorsData.size(); ++i){
		writeAntDoorData(*doorsData[i]);
	}
}

bool LCDManager::isRefreshDelayExceeded(unsigned long currentTime) {
	return (currentTime - lastChangeTime) > refreshDelay;
}

bool LCDManager::isOverflow(unsigned long currentTime) {
	return currentTime < lastChangeTime;
}

void LCDManager::update(unsigned long currentTime) {
	if (isRefreshDelayExceeded(currentTime) || isOverflow(currentTime)) {
		refreshDisplay();
		lastChangeTime = currentTime;
	}
}

void LCDManager::addAntDoorData(const AntDoorData& antDoorData) {
	doorsData.push_back(&antDoorData);
}

void LCDManager::writeDateTime(const DateTime& dateTime) {
	lcd->setCursor(0, 1);
	lcd->print(dateTime.hour());
	lcd->print(":");
	if (dateTime.minute() < 10) {
		lcd->print("0");
	}
	lcd->print(dateTime.minute());
	lcd->print(":");

	if (dateTime.second() < 10) {
		lcd->print("0");
	}
	lcd->print(dateTime.second());

	lcd->setCursor(9, 1);
	if (dateTime.day() < 10) {
		lcd->print("0");
	}
	lcd->print(dateTime.day());
}

void LCDManager::writeAntDoorData(const AntDoorData& antDoorData)  {
	lcd->print(antDoorData.getNbIn());
	lcd->print(";");
	lcd->print(antDoorData.getNbOut());
	lcd->print(";");
	lcd->print(antDoorData.getStock());
	lcd->print("; ");
}
