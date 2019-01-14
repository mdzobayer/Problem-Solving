#pragma once
enum class chainedColor { Black, Red, Silver, White };
class CarChained
{
public:
    CarChained();
    CarChained(chainedColor col);
    CarChained(chainedColor col, int engsize);
    CarChained(chainedColor col, int engsize, double cost);
private:
    chainedColor primaryColor;
    int engineSize;
    double price;
};
