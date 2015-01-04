#include "AntDoorManager.h"
#define MAX_TRAVERSING_DURATION 500

const NoAntState _noAntState(0);
const AbstractAntDoorState* const AntDoorManager::noAntState = &_noAntState;

const AntEnteringState _antEnteringState(1);
const AbstractAntDoorState* const AntDoorManager::antEnteringState = &_antEnteringState;

const AntEnteredState _antEnteredState(2);
const AbstractAntDoorState* const AntDoorManager::antEnteredState = &_antEnteredState;

const AntExitingState _antExitingState(3);
const AbstractAntDoorState* const AntDoorManager::antExitingState = &_antExitingState;

const AntExitedState _antExitedState(4);
const AbstractAntDoorState* const AntDoorManager::antExitedState = &_antExitedState;

bool isRisingEdge(bool const oldState, bool const newState){
	return 0 == oldState && 1 == newState;
}

bool isFallingEdge(bool const oldState, bool const newState){
	return 1 == oldState && 0 == newState;
}

struct AntDoorManager::AntIn: public DigitalInputChangeListener {
	AntIn(AntDoorManager* antDoorManager) :
			antDoorManager(antDoorManager) {
	}

	virtual ~AntIn() {
	}

	virtual void operator()(bool const oldState, bool const newState) {
		if (isRisingEdge(oldState, newState)) {
			if (antDoorManager->currentState == noAntState) {
				antDoorManager->antData.startTraversingTimer();
				antDoorManager->stateChanged(antEnteringState);
			} else if (antDoorManager->currentState == antExitingState) {
				antDoorManager->antData.resetTraversingTimer();
				antDoorManager->stateChanged(antExitedState);
			}
		} else if (isFallingEdge(oldState, newState)) {
			if (antDoorManager->currentState == antExitedState){
				antDoorManager->antData.antOut();
				antDoorManager->stateChanged(noAntState);
			}
		}
	}
	AntDoorManager* antDoorManager;
};

struct AntDoorManager::AntOut: public DigitalInputChangeListener {
	AntOut(AntDoorManager* antDoorManager) :
			antDoorManager(antDoorManager) {

	}

	virtual ~AntOut() {
	}

	virtual void operator()(bool const oldState, bool const newState) {
		if (isRisingEdge(oldState, newState)) {
			if (antDoorManager->currentState == noAntState) {
				antDoorManager->antData.startTraversingTimer();
				antDoorManager->stateChanged(antExitingState);
			} else if (antDoorManager->currentState == antEnteringState) {
				antDoorManager->antData.resetTraversingTimer();
				antDoorManager->stateChanged(antEnteredState);
			}
		} else if (isFallingEdge(oldState, newState)) {
			if (antDoorManager->currentState == antEnteredState){
				antDoorManager->antData.antIn();
				antDoorManager->stateChanged(noAntState);

			}
		}
	}

	AntDoorManager* antDoorManager;
};

AntDoorManager::AntDoorManager(AntDoor const & antDoor) :
		antDoor(antDoor),
		currentState(noAntState),
		antEntered(new AntIn(this)),
		antExited(new AntOut(this)) {
	this->antDoor.attachIn(antEntered);
	this->antDoor.attachOut(antExited);
}

AntDoorManager::~AntDoorManager() {
	delete antEntered;
	delete antExited;
}

void AntDoorManager::stateChanged(const AbstractAntDoorState * const newState) {
	const AbstractAntDoorState * const oldState = currentState;
	currentState = newState;
	newState->activate();

	Serial.print("State changed: ");
	Serial.print(*oldState);
	Serial.print(" -> ");
	Serial.println(*newState);

	Serial.print("In : ");
	Serial.print(antData.getNbIn());
	Serial.print(", Out :");
	Serial.println(antData.getNbOut());
}

void AntDoorManager::update(unsigned long currentTime) {
	antDoor.update(currentTime);

	if ((currentState == antEnteringState || currentState == antExitingState)
			&& (currentTime - antData.getTraversingTimer() > MAX_TRAVERSING_DURATION)) {
		stateChanged(noAntState);
		antData.resetTraversingTimer();
	}
}
