#include <iostream>

using namespace std;

namespace minMax {
    int min(int num1, int num2) {
        if (num1 < num2) {
            return num1;
        }
        else {
            return num2;
        };
    };

    int max(int num1, int num2) {
        if (num1 > num2) {
            return num1;
        }
        else {
            return num2;
        };
    };
};

namespace People {
    class Person {
        private:
            string name;
            string sex;

        public:
            Person(string n, string s) {
                name = n;
                sex = s;
            };
            string get() {
                return name + ", " + sex;
            };
    };
};

int main() {

    //using namespace minMax;
    //using namespace People;
    int a,b;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Enter another number: ";
    cin >> b;
    cout << minMax::min(a,b) << endl;
    cout << minMax::max(a,b) << endl;
    cout << endl;
    class People::Person you("Zobayer Mahmud", "M");
    cout << you.get() << endl;

    return (0);
}
