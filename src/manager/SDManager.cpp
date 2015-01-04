/*
 * SDManager.cpp
 *
 *  Created on: 30 oct. 2014
 *      Author: sebastien
 */

#include "SDManager.h"
#include "DeviceManager.h"

SDManager::SDManager():lastChangeTime(0UL), refreshDelay(DEFAULT_REFRESH_DELAY) {}

SDManager::~SDManager() {
}

void SDManager::update(unsigned long currentTime)  {
	if ((currentTime - lastChangeTime) > refreshDelay) {
		refresh();
		lastChangeTime = currentTime;
	}
}

void SDManager::addAntDoorData(const AntDoorData& antDoorData)  {
	doorsData.push_back(&antDoorData);
}

void SDManager::refresh() {
	openFile("mylou.csv");
	writeDateTime(DeviceManager::getInstance()->getDateTime());
	for(size_t i = 0; i < doorsData.size(); ++i){
		writeAntDoorData(*doorsData[i]);
	}
	closeFile();
}

void SDManager::openFile(const char* filepath) {
	file = SD.open(filepath, FILE_WRITE);
}

void SDManager::writeDateTime(const DateTime& dateTime) {
	file.print(dateTime.day());
	file.print(";");
	file.print(dateTime.month());
	file.print(";");
	file.print(dateTime.hour());
	file.print(";");
	file.print(dateTime.minute());
	file.print(";");
}

void SDManager::writeAntDoorData(const AntDoorData& antDoorData) {
	file.print(antDoorData.getNbIn());
	file.print(";");
	file.print(antDoorData.getNbOut());
	file.print(";");
	file.print(antDoorData.getStock());
	file.print("; ");
}

void SDManager::closeFile() {
		file.println() ;
		file.close();
}
