#ifndef ANT_ENTERING_STATE_H_
#define ANT_ENTERING_STATE_H_

#include "AbstractAntDoorState.h"

class AntEnteringState: public AbstractAntDoorState {
public:
	AntEnteringState(unsigned int const id);
	virtual ~AntEnteringState() {
	}
	virtual void activate() const;
private:
	AntEnteringState();
};

#endif /* ANT_ENTERING_STATE_H_ */
