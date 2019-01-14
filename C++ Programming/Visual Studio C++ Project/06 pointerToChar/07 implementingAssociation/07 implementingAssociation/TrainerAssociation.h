#pragma once
// Class TrainerAssociation specifies a course tutor.
// It will be used in a variable association
#include <string>
using namespace std;

class TrainerAssociation
{
public:
	TrainerAssociation(string tName, string tID)
		: name{ tName }, trainerID{ tID }
	{
		// trainer constructor
	}

	~TrainerAssociation() = default;
private:
	string name;
	string trainerID;
};

