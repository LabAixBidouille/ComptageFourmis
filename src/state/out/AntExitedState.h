#ifndef ANT_EXITED_STATE_H_
#define ANT_EXITED_STATE_H_

#include "AbstractAntDoorState.h"

class AntExitedState: public AbstractAntDoorState {
public:
	AntExitedState(unsigned int const id);
	virtual void activate() const;
private:
	AntExitedState();
};

#endif /* ANT_EXITED_STATE_H_*/
