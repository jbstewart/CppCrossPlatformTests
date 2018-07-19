#ifndef SIMPLE_EXAMPLE_SUT_H
#define SIMPLE_EXAMPLE_SUT_H

#include "SimpleExampleInterface.h"

class SystemUnderTest {
public:
	SystemUnderTest(Interface& theClass) : _theClass(theClass) {}

	std::string Act() {
		_theClass.SetPropC("foo");
		if (_theClass.DoThingB() < 5) {
			_theClass.DoThingA();
			_theClass.SetPropC("farkle");
		}
		return _theClass.GetPropC();
	}

private:
	Interface & _theClass;
};

#endif // !SIMPLE_EXAMPLE_SUT_H
