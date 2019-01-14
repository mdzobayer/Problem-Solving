#include "CarChained.h"

CarChained::CarChained()
    :CarChained(chainedColor::Red) { }

CarChained::CarChained(chainedColor col)
    :CarChained(col, 2000) { }

CarChained::CarChained(chainedColor col, int engsize)
    :CarChained(col, engsize, 20000) { }

CarChained::CarChained(chainedColor col, int engsize, double cost)
    :primaryColor{ col }, engineSize{ engsize }, price{ cost }
{
    //primaryColor = col;
    //engineSize = engsize;
    //price = cost;
}
