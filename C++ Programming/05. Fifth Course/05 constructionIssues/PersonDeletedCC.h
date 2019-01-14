#pragma once
class PersonDeletedCC
{
public:
    PersonDeletedCC();
    PersonDeletedCC(char* name);
    PersonDeletedCC(const PersonDeletedCC& p) = delete;
    ~PersonDeletedCC();
    char* GetName() const;
private:
    char* name;
};
