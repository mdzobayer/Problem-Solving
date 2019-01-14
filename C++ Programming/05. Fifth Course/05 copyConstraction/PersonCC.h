#pragma once
class PersonCC
{
public:
    PersonCC();
    PersonCC(char* name);
    PersonCC(const PersonCC& p);
    ~PersonCC();
    char* GetName() const;
private:
    char* name;
};
