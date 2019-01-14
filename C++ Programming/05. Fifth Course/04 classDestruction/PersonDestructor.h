#pragma once
#ifndef PersonDestructor_h_
#define PersonDestructor_h_
class PersonDestructor
{
public:
    //----- Constructor --------
    PersonDestructor();
    //--- Overloaded Constructor ---
    PersonDestructor(char *nam);
    //--- Destructor ---
    ~PersonDestructor();
    void UsePerson();
private: //data item
    char* name;
};
#endif // PersonDestructor_h_
