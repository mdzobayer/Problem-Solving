#pragma once
class A
{
public:
	int x;
protected:
	int y;
private:
	int z;
};

class B : public A
{
public:
	void DoSomething()
	{
		x = 10;	// x is public
		y = 20;	// y is protected
		// z = 20; // z is not accessible from B
	}
};

class c : protected A
{
public:
	void DoSomething()
	{
		x = 40;	// x is protected
		y = 50;	// y is protected
		// z = 60; // z is not accessible from c
	}
};

class D : private A
{
public:
	void DoSomething()
	{
		x = 70;	// x is private
		y = 80;	// x is private
		// z = 90; // z is not accessible from D
	}
};