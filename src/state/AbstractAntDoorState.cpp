#include "AbstractAntDoorState.h"

AbstractAntDoorState::AbstractAntDoorState(const unsigned int id) :
		id(id) {
}

const unsigned int AbstractAntDoorState::getId() const {
	return id;
}

size_t AbstractAntDoorState::printTo(Print& p) const {
	size_t size = p.print("Etat(");
	size += p.print(getId());
	size += p.print(")");
	return size;
}
