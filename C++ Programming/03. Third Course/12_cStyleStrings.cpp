#include <iostream>
#include <cstring>

using namespace std;

int main() {

    // C-style strings

    char c1[] = {'H','e','l','l','o','\0'};
    char c2[] = " World";
    cout << c1 << " " << c2 << endl;
    int value = strcmp(c1,c2);
    cout << value << endl;
    strcat(c1, c2);
    cout << c1 << endl;

    return (0);
}
