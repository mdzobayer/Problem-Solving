
#pragma once
#include <string>
using namespace std;

class PersonInline
{
    PersonInline();
    ~PersonInline();
    void implicitInlineUsePerson()
    {
        // do something
    }
    void inline ExplicitInlinePerson()
    {
        // do something
    }
    void inline ExplicitInlineUsePersonAgain();
private:
    string name;
};
