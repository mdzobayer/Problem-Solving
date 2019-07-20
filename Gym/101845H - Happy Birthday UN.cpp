#include <bits/stdc++.h>


using namespace std;

bool LeapYear(int y) {

    if (y % 400 == 0) return true;
    else if ((y % 4 == 0) && (y % 100 != 0)) {
        return true;
    }

    return false;
}

int main() {

    int n, iniYear = 1868;

    cin >> n;

    int days = 0;

    for ( ;iniYear < (n + 1868); ++iniYear) {
        if (LeapYear(iniYear)) {
            days += 366;
        }
        else {
            days += 365;
        }
    }

//    if (n > 0) {
//        days -= 100;
//    }

    int bar = days % 7;

    if (bar == 0) {
        puts("Sunday");
    }
    else if (bar == 1) {
        puts("Monday");
    }
    else if (bar == 2) {
        puts("Tuesday");
    }
    else if (bar == 3) {
        puts("Wednesday");
    }
    else if (bar == 4) {
        puts("Thursday");
    }
    else if (bar == 5) {
        puts("Friday");
    }
    else if (bar == 6) {
        puts("Saturday");
    }

    return (0);
}
