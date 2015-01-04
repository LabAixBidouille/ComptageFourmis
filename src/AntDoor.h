#ifndef ANT_DOOR_H_
#define ANT_DOOR_H_

#include "OpticalBarrier.h"
#include "Updatable.h"

class AntDoor: public Updatable {
public:
	AntDoor(int const pinIn, int const pinOut);

	virtual void update(unsigned long currentTime);

	void attachIn(DigitalInputChangeListener* listenerIn) {
		barrierIn.attach(listenerIn);
	}

	void attachOut(DigitalInputChangeListener* listenerOut) {
		barrierOut.attach(listenerOut);
	}
private:
	OpticalBarrier barrierIn;
	OpticalBarrier barrierOut;
};

#endif /* ANT_DOOR_H_ */
