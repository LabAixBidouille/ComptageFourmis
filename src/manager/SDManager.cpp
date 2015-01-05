/*
 * SDManager.cpp
 *
 *  Created on: 30 oct. 2014
 *      Author: sebastien
 */

#include "SDManager.h"
#include "DeviceManager.h"

void SDManager::writeHeader() {
	openFile("mylou.csv");
	file.print("Day");
	file.print(";");
	file.print("Month");
	file.print(";");
	file.print("Hour");
	file.print(";");
	file.print("Minute");
	file.print(";");
	for (size_t i = 0; i < doorsData.size(); ++i) {
		file.print("In ");
		file.print((char) (('A' + i)));
		file.print(";");
		file.print("Out ");
		file.print((char) (('A' + i)));
		file.print(";");
		file.print("Stock ");
		file.print((char) (('A' + i)));
		file.print(";");
	}
	closeFile();
}

SDManager::SDManager():lastChangeTime(0UL), refreshDelay(DEFAULT_REFRESH_DELAY), doorsData(10), firstRefresh(true){
}

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

void SDManager::writeCurrentData() {
	openFile("mylou.csv");
	writeDateTime(DeviceManager::getInstance()->getDateTime());
	for (size_t i = 0; i < doorsData.size(); ++i) {
		writeAntDoorData(*doorsData[i]);
	}
	closeFile();
}

void SDManager::refresh() {
	if(firstRefresh){
		writeHeader();
		firstRefresh = false;
	}
	writeCurrentData();
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
