#ifndef NO_ANT_STATE_H_
#define NO_ANT_STATE_H_

#include "AbstractAntDoorState.h"

class NoAntState: public AbstractAntDoorState {
public:
	NoAntState(unsigned int const id);
	virtual void activate() const;

private:
	NoAntState();
};

#endif /* NO_ANT_STATE_H_ */
