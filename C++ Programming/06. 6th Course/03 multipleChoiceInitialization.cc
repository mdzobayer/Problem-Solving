#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char *[])
{
    /*const string s1
    = argc == 0 ? "0 Arguments" :
        (argc == 1 ? "1 Arguments" : "Many Arguments");

    return s1.size();*/

    const string s1 = [&]() {
        switch (argc) {
        case 0: return "0 Arguments";
        case 1: return "1 Arguments";
        default: return "Many Arguments";
        }
    }();
    //return s1.size();

    vector<int> vec(25, 0);
    vec[10] = 18;

    return vec[10];
}
