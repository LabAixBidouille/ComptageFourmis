#ifndef ABSTRACT_ANT_DOORSTATE_H_
#define ABSTRACT_ANT_DOORSTATE_H_
#include <Arduino.h>

class AbstractAntDoorState: public Printable {
public:
	AbstractAntDoorState(unsigned int const id);
	virtual ~AbstractAntDoorState() {}
	virtual void activate() const = 0;
	virtual size_t printTo(Print& p) const;
	unsigned int const getId() const;

private:
	AbstractAntDoorState();
	unsigned int const id;
};

#endif /* ABSTRACT_ANT_DOORSTATE_H_ */
