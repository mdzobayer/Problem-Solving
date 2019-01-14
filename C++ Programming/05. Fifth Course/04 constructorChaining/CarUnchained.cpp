#include "CarChained.h"

CarUnchained::CarUnchained()
    :primaryColor{ unchainedcolor::Red }, engineSize{ 2000 }, price{ 20000 }
{
    //primaryColor = Red;
    //engineSize = 2000;
    //price = 20000;
}
CarUnchained::CarUnchained(unchainedcolor col)
    :primaryColor{ col }, engineSize{ 2000 }, price{ 20000 }
{
    //primaryColor = col;
    //engineSize = 2000;
    //price = 20000;
}
CarUnchained::CarUnchained(unchainedcolor col, int engSize)
    :primaryColor{ col }, engineSize{ engsize }, price{ 20000 }
{
    //primaryColor = col;
    //engineSize = engSize;
    //price = 20000;
}
CarUnchained::CarUnchained(unchainedcolor col, int engSize, double cost)
    :primaryColor{ col }, engineSize{ engsize }, price{ cost }
{
    //primaryColor = col;
    //engineSize = engSize;
    //price = cost;
}
