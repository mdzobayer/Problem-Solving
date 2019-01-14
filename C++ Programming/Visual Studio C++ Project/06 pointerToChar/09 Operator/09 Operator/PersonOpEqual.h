#pragma once
class PersonCC
{
public:
	PersonCC();				// default consturctor
	PersonCC(char* name);	// overloaded consturctor
	PersonCC(const PersonCC& p);	// copy constructor
	~PersonCC();			// destructor
	char* GetName() const;	// query function
	PersonCC& operator = (const PersonCC& rhs);	// assignment operator
private:
	char* name;
};