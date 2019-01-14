#pragma once
class PersonConstractionIssues
{
public:
    // Default Constructor
    PersonConstractionIssues();
    // Overloaded Constructor
    PersonConstractionIssues(char* name);
    // Destructor
    ~PersonConstractionIssues();
    // Query Function
    char* GetName() const;
private:
    // Data Member
    char* name;
};
