class base
{
public:
	virtual void foo()
	{
		// ...
	}
};

class derived : public base
{
public:
	// any attempt to further override foo 
	// function resutl an error for final keyword
	// final prevent further overriding 
	void foo() override final	// virtual as it override base::f
	{
		// ..
	}
};

class mostDerived : public derived
{
public:

	void foo()	// error: cannot override!
	{
		// ...
	}
};