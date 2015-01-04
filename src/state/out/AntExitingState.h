#ifndef ANT_EXITING_STATE_H_
#define ANT_EXITING_STATE_H_

#include "AbstractAntDoorState.h"

class AntExitingState: public AbstractAntDoorState {
public:
	AntExitingState(unsigned int const id);
	virtual ~AntExitingState() {
	}
	virtual void activate() const;

private:
	AntExitingState();
};

#endif /* ANT_EXITING_STATE_H_*/
