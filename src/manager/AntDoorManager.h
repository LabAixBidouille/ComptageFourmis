#ifndef ANT_DOOR_MANAGER_H_
#define ANT_DOOR_MANAGER_H_

#include "AntDoor.h"
#include "AntDoorData.h"
#include "AbstractAntDoorState.h"
#include "AntEnteringState.h"
#include "AntEnteredState.h"
#include "AntExitingState.h"
#include "AntExitedState.h"
#include "NoAntState.h"

class AntDoorManager: public Updatable {
public:
	AntDoorManager(AntDoor const & antDoor);
	virtual ~AntDoorManager();
	virtual void update(unsigned long currentTime);

	const AntDoorData& getAntData() const {
		return antData;
	}

private:
	AntDoor antDoor;
	AntDoorData antData;

	void stateChanged(const AbstractAntDoorState * const newState);

	const AbstractAntDoorState* currentState;

	static const AbstractAntDoorState* const noAntState;
	static const AbstractAntDoorState* const antEnteringState;
	static const AbstractAntDoorState* const antEnteredState;
	static const AbstractAntDoorState* const antExitingState;
	static const AbstractAntDoorState* const antExitedState;

	DigitalInputChangeListener* antEntered;
	DigitalInputChangeListener* antExited;

	struct AntIn;
	struct AntOut;
};

#endif /* ANT_DOOR_MANAGER_H_ */
