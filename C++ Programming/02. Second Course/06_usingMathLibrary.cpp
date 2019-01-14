#include <iostream>
#include <cmath>

using namespace std;

int main(){
    //const double pi = 3.14159265;
    double area;
    int radius = 3;
    area = M_PI * pow(radius,2);
    cout << "The area of a circle with radius 3 is " << area << endl;
    cout << sqrt(144) << endl;
    cout << abs(1345) << " " << abs(-1345) << endl;
    //cout << 23.45 % 3; (Doesn't work directly)
    cout << fmod(23.45, 3) << endl;
    return (0);

}
