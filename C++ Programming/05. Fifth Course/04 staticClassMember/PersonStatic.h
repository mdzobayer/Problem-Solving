#pragma once
class PersonStatic
{
public:

    PersonStatic();
    ~PersonStatic();
    // other class member functions here
    // static function can only access static data
    static int GetNumPeople();
private:
    // class member data here
    static int numpeople;
};
