#include "AntDoor.h"

AntDoor::AntDoor(int const pinIn, int const pinOut) :
		barrierIn(pinIn), barrierOut(pinOut){
}

void AntDoor::update(unsigned long currentTime) {
	barrierIn.update(currentTime);
	barrierOut.update(currentTime);
}
