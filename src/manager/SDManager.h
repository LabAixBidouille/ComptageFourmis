/*
 * SDManager.h
 *
 *  Created on: 30 oct. 2014
 *      Author: sebastien
 */

#ifndef SDMANAGER_H_
#define SDMANAGER_H_

#include <SD.h>
#include <RTClib.h>
#include "AbstractManager.h"
#include "Updatable.h"
#include "AntDoorData.h"
#include "Vector.h"

#define DEFAULT_REFRESH_DELAY 10000

class SDManager: public AbstractManager<SDManager>, public Updatable {
public:
	SDManager();
	virtual ~SDManager();
	virtual void update(unsigned long currentTime);
	void addAntDoorData(const AntDoorData& antDoorData);
	void setRefreshDelay(unsigned int refreshDelay) {
		this->refreshDelay = refreshDelay;
	}

private:
	unsigned long lastChangeTime;
	unsigned int refreshDelay;
	Vector<const AntDoorData*> doorsData;
	File file;

	void openFile(const char *filepath) ;
	void closeFile();
	void refresh();
	void writeDateTime(const DateTime& dateTime);
	void writeAntDoorData(const AntDoorData& antDoorData);
};

#endif /* SDMANAGER_H_ */
