/*
 * AntDoorData.h
 *
 *  Created on: 30 oct. 2014
 *      Author: sebastien
 */

#ifndef ANTDOORDATA_H_
#define ANTDOORDATA_H_

class AntDoorData {
public:
	AntDoorData();
	virtual ~AntDoorData();

	int getNbIn() const;
	void antIn();

	int getNbOut() const;
	void antOut();

	int getStock() const;


	unsigned long getTraversingTimer() const;
	void startTraversingTimer();
	void resetTraversingTimer();

private:
	int nbIn;
	int nbOut;
	unsigned long traversingTimer;
};

#endif /* ANTDOORDATA_H_ */
