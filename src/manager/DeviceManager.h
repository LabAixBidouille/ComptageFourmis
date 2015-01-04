/*
 * DeviceManager.h
 *
 *  Created on: 30 oct. 2014
 *      Author: sebastien
 */

#ifndef DEVICEMANAGER_H_
#define DEVICEMANAGER_H_


#include <SD.h>
#include <RTClib.h>
#include <AbstractManager.h>
#include <Updatable.h>
#include "AntDoorData.h"

class DeviceManager :public AbstractManager<DeviceManager>, public Updatable {
public:
	DeviceManager();
	virtual ~DeviceManager();
	virtual void update(unsigned long currentTime);
	DateTime getDateTime() const {
		return rtc.now();
	}

private:
	RTC_DS1307 rtc;
};

#endif /* DEVICEMANAGER_H_ */
