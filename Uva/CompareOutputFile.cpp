#include <iostream>
#include <fstream>

using namespace std;

int main() {

    string data1, data2;
    ifstream input1, input2;
    input1.open("out.txt");
    input2.open("testOut.txt");
    int i = 1;
    bool flag = true;
    while(getline(input1, data1)) {
        getline(input2, data2);
        if (data1 != data2) {
            cout << "Not identical on Line " << i << endl;
            cout << data1 << endl;
            cout << data2 << endl;
            flag = false;
            break;
        }
        ++i;
    }
    if (flag) {
        cout << "Oooh! Both are identical" << endl;
    }
    input1.close();
    input2.close();

    return (0);
}
