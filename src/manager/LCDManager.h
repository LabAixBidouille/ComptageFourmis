#ifndef LCD_MANAGER_H_
#define LCD_MANAGER_H_

#include <LiquidCrystal.h>
#include <RTClib.h>
#include "AbstractManager.h"
#include "AntDoorData.h"
#include "Updatable.h"
#include "Vector.h"

#define DEFAULT_REFRESH_DELAY 1000

class LCDManager: public AbstractManager<LCDManager>, public Updatable {
public:
	LCDManager();
	virtual void update(unsigned long currentTime);
	void addAntDoorData(const AntDoorData* antDoorData);

	void setLcd(LiquidCrystal* lcd) {
		this->lcd = lcd;
	}

	void setRefreshDelay(unsigned int refreshDelay) {
		this->refreshDelay = refreshDelay;
	}

private:
	LiquidCrystal* lcd;
	unsigned long lastChangeTime;
	unsigned int refreshDelay;
	Vector<const AntDoorData*> doorsData;

	void refreshDisplay();
	void write(const char* text);
	void writeDateTime(const DateTime* dateTime);
	void writeAntDoorData(const AntDoorData* antDoorData);
};

#endif /* LCD_MANAGER_H_ */
