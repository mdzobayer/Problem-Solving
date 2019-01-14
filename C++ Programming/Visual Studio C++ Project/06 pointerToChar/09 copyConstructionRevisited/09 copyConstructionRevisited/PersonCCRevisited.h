#pragma once
class PersonCC
{
public:
	PersonCC();					// default constuctor
	PersonCC(char* name);		// overloaded constuctor
	PersonCC(const PersonCC& p); // copy constuctor
	~PersonCC();				// destructor
	char* GetName() const;		// query function
private:
	char* name;
};
