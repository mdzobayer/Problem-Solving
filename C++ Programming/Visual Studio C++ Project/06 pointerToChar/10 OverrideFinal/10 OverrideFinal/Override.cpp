class Base
{
public:
	virtual int foo() const
	{
		// ...
	}
};

class Derived : Base
{
public:
	/*
	override force the compiler to do a check
	it search the base class for a function 
	of exectly the same name with exectly the same signature
	*/
	virtual int foo() override	// whoops!
	{
		// ...
	}
};