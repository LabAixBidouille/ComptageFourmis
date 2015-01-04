/*
 * Observable.h
 *
 *  Created on: 30 oct. 2014
 *      Author: sebastien
 */

#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include "Vector.h"
#include "InputChangeListener.h"

template<typename Listener>
class Observable{
public:
	Observable(){}

	virtual ~Observable(){}

	void attach(Listener* listener) {
		this->listeners.push_back(listener);
	}

	void notify(bool const oldState, bool const newState){
		// Ping listeners
		for (size_t i = 0; i < listeners.size(); ++i) {
			Listener* listenerCour = listeners[i];
			if (listenerCour) {
				(*listenerCour)(oldState, newState);
			}
		}
	}

private:
	Vector<Listener*> listeners;
};

#endif /* OBSERVABLE_H_ */
