#ifndef SIMPLE_EXAMPLE_INTERFACE_H
#define SIMPLE_EXAMPLE_INTERFACE_H

class Interface {
public:
	virtual ~Interface() {}
	virtual void DoThingA() = 0;
	virtual int DoThingB() = 0;
	virtual std::string GetPropC() = 0;
	virtual void SetPropC(std::string val) = 0;
};

#endif // !SIMPLE_EXAMPLE_INTERFACE_H
