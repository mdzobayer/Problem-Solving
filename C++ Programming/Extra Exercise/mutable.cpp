#include <iostream>
using namespace std;

class Demo {
    mutable int i;
    int j;
public:
    void seti(int x) const {
        i = x; //
    }
    int geti() const {
        return i;
    }
    /// This will not compile
    void setj(int x) const {
        j = x;
    }
};

int main() {

    Demo ob;

    ob.seti(1900);
    cout << ob.geti() << endl;

    return (0);
}
