#include <Wire.h>
#include <SD.h>
#include <LiquidCrystal.h>
#include "RTClib.h"

#include "SDManager.h"
#include "LCDManager.h"
#include "AntDoorManager.h"

#define CHIPSELECT 53

AntDoor doorA(30, 31);
AntDoorManager doorManagerA(doorA);

AntDoor doorB(32, 33);
AntDoorManager doorManagerB(doorB);

AntDoor doorC(34, 35);
AntDoorManager doorManagerC(doorC);

AntDoor doorD(36, 37);
AntDoorManager doorManagerD(doorD);

LCDManager* lcdManager;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

SDManager* sdManager;

void setup() {
	lcdManager = LCDManager::getInstance();
	Serial.begin(9600);

	Serial.print("Initializing LCD...");
	lcd.begin(16, 2);
	lcdManager->setLcd(&lcd);
	lcdManager->addAntDoorData(doorManagerA.getAntData());
	lcdManager->addAntDoorData(doorManagerB.getAntData());
	lcdManager->addAntDoorData(doorManagerC.getAntData());
	lcdManager->addAntDoorData(doorManagerD.getAntData());

	Serial.println("LCD initialized.");

	Serial.print("Initializing SD card...");
	// see if the card is present and can be initialized:
	if (!SD.begin(CHIPSELECT)) {
		Serial.println("Card failed, or not present");
		return;
	}
	sdManager = SDManager::getInstance();
	sdManager->addAntDoorData(doorManagerA.getAntData());
	sdManager->addAntDoorData(doorManagerB.getAntData());
	sdManager->addAntDoorData(doorManagerC.getAntData());
	sdManager->addAntDoorData(doorManagerD.getAntData());

	Serial.println("card initialized.");
}

void loop() {
	doorManagerA.update(millis());
	doorManagerB.update(millis());
	doorManagerC.update(millis());
	doorManagerD.update(millis());
	lcdManager->update(millis());
	sdManager->update(millis());
}