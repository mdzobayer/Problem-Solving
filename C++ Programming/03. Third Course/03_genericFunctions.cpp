#include <iostream>

using namespace std;

template <typename T>
void display(T arr[], int size) {
    for(int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
};
template <typename T>
T max (T &arg1, T &arg2) {
    return (arg1 > arg2) ? arg1 : arg2;
}
int main() {
    /*const int size = 10;
    int numbers[size];
    for(int i = 0; i < size; ++i) {
        numbers[i] = i + 1;
    };
    display(numbers,size);
    string names[] = {"Jim","Fred","Jane","Bob","Mary",
                      "Mike","Terri","Allison","Mason",
                      "Meredith"};
    display(names,size);*/
    cout << endl;
    int a = 12;
    int b = 24;
    cout << max(a,b) << endl;
    double x = 2.25;
    double y = .25;
    cout << max(x,y) << endl;
    string w1 = "apple";
    string w2 = "aardvark";
    cout << max(w1,w2) << endl;
    return (0);
};

