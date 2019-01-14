#include <iostream>

using namespace std;

enum weekDays {Sunday, Monday, Tuesday, Wednessday, Thursday, Saturday};
enum status {OK = 0, Warning = 5, Error, Fatal = 999};
enum class color {Red, Yellow, Blue, Green};
enum class mood {Happy, Blue, Excited, Indifferent};

int main() {

    color myFavourite = color::Red;
    mood howIfeel = mood::Blue;
//    color royal = mood::Blue;

    return (0);
}
