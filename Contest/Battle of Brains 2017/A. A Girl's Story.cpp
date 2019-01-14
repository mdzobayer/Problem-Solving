#include <iostream>
#define ull unsigned long long int
int main() {

    ull x, y;
    double raju;
    std::ios::sync_with_stdio(false);
    std::cin >> x >> y;
    y -= x;
    y /= 2;
    y += x;
    std::cout << y << std::endl;

    return (0);
}
