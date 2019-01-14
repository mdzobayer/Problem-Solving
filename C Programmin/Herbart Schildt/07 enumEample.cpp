#include <iostream>

using namespace std;
enum coin { penny, nickel, dime, quarter = 100, half_dollar, dollar};
int main() {


    enum coin money;
    money = dollar;
    cout << money << endl;

    return (0);
}
