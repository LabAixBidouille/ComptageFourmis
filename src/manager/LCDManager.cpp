#include <Arduino.h>
#include "LCDManager.h"
#include "DeviceManager.h"

LCDManager::LCDManager() :
		 lcd(0),lastChangeTime(0UL), refreshDelay(DEFAULT_REFRESH_DELAY) {
	lastChangeTime = millis();
}

void LCDManager::refreshDisplay() {
	writeDateTime(DeviceManager::getInstance()->getDateTime());
	lcd->setCursor(0, 0);
	for(size_t i = 0; i < doorsData.size(); ++i){
		writeAntDoorData(*doorsData[i]);
	}
}

void LCDManager::update(unsigned long currentTime) {
	if ((currentTime - lastChangeTime) > refreshDelay) {
		refreshDisplay();
		lastChangeTime = currentTime;
	}
}

void LCDManager::addAntDoorData(const AntDoorData& antDoorData) {
	doorsData.push_back(&antDoorData);
}

void LCDManager::write(const char* text) {
	lcd->setCursor(0, 0);
	lcd->print(text);
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
