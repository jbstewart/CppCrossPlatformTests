#ifndef SIMPLE_EXAMPLE_CLASS_H
#define SIMPLE_EXAMPLE_CLASS_H

#include "SimpleExampleInterface.h"

class RealClass : public Interface {
public:
	virtual void DoThingA() {
		std::cout << "ThingA";
	}

	virtual int DoThingB() {
		std::cout << "ThingA";
	}

	virtual std::string GetPropC() {
		return _propC;
	}

	virtual void SetPropC(std::string val) {
		_propC = val;
	}

private:
	std::string _propC;

};

#endif // !SIMPLE_EXAMPLE_CLASS_H