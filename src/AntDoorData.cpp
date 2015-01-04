/*
 * AntDoorData.cpp
 *
 *  Created on: 30 oct. 2014
 *      Author: sebastien
 */

#include "AntDoorData.h"
#include <Arduino.h>

AntDoorData::AntDoorData():nbIn(0), nbOut(0), traversingTimer(0UL) {
}

AntDoorData::~AntDoorData() {

}

int AntDoorData::getNbIn() const {
	return nbIn;
}

void AntDoorData::antIn() {
	this->nbIn++;
}

int AntDoorData::getNbOut() const {
	return nbOut;
}

void AntDoorData::antOut() {
	this->nbOut++;
}

unsigned long AntDoorData::getTraversingTimer() const {
	return traversingTimer;
}

void AntDoorData::startTraversingTimer(){
	traversingTimer = millis();
}
void AntDoorData::resetTraversingTimer(){
	traversingTimer = 0UL;
}

int AntDoorData::getStock() const 	{
	return getNbIn() - getNbOut();
}
