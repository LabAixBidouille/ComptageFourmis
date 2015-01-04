#ifndef ABSTRACTMANAGER_H_
#define ABSTRACTMANAGER_H_

template<typename T>
class AbstractManager {
protected:
	AbstractManager() {
	}

	virtual ~AbstractManager() {
	}
public:
	// Interface publique
	static T* getInstance() {
		if (0 == singleton) {
			singleton = new T;
		}

		return singleton;
	}
	static void kill() {
		if (0 != singleton) {
			delete singleton;
			singleton = 0;
		}
	}

private:
	static T *singleton;
};

template<typename T>
T* AbstractManager<T>::singleton = 0;

#endif /* ABSTRACTMANAGER_H_ */
