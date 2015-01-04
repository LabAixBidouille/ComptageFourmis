#ifndef ANT_ENTERED_STATE_H_
#define ANT_ENTERED_STATE_H_

#include "AbstractAntDoorState.h"

class AntEnteredState: public AbstractAntDoorState {
public:
	AntEnteredState(unsigned int const id);
	virtual ~AntEnteredState() {
	}
	virtual void activate() const;

private:
	AntEnteredState();
};

#endif /* ANT_ENTERED_STATE_H_ */
