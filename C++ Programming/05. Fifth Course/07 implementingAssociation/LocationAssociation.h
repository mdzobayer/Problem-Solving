#pragma once
// Class LocationAssociation specifies a course location.
// It will be used in a constant association
#include <string>

using namespace std;

class LocationAssociation
{
public:
    LocationAssociation(string locID, int locRoom)
        : centreID{ locID }, roomNumber{ locRoom }
    {
        // Location Constructor
    }

    ~LocationAssociation() = default;
private:
    string centreID;
    int roomNumber;
};
