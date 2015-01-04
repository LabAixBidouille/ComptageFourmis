#ifndef INPUT_CHANGE_LISTENER_H_
#define INPUT_CHANGE_LISTENER_H_

class DigitalInputChangeListener {
public:
	virtual void operator()(bool const oldState, bool const newState) = 0;
	virtual ~DigitalInputChangeListener() {
	}
};

typedef void (*InputChangeListenerFunctionPointer)(bool const oldState, bool const newState);

struct InputChangeListenerFunctionAdapter: public DigitalInputChangeListener {
	InputChangeListenerFunctionAdapter(InputChangeListenerFunctionPointer listener):listener(listener) {

	}

	virtual void operator()(bool const oldState, bool const newState) {
		listener(oldState, newState);
	}

	InputChangeListenerFunctionPointer listener;
};

#endif /* INPUT_CHANGE_LISTENER_H_ */
