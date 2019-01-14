#include "PersonStatic.h"

// static variable
int PersonStatic::numpeople;

PersonStatic::PersonStatic()
{
    ++numpeople;
}
PersonStatic::~PersonStatic()
{
    --numpeople;
}
int PersonStatic::GetNumPeople()
{
    return numpeople;
}
