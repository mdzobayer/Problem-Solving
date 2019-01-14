#pragma once
// Class DelegateAssociation specifies a course delegate.
// It will be used in a variable association custody of delegate
// objects is with the CourseAssociation class. It is this class
// that creates, manages & deletes DelegateAssociation objects.
#include <string>
using namespace std;

class DelegateAssociation
{
public:
	DelegateAssociation(string dName, string dAddress)
		: name{ dName }, address{ dAddress }
	{
		// delegate constructor
	}

	~DelegateAssociation() = default;
private:
	string name;
	string address;
};

