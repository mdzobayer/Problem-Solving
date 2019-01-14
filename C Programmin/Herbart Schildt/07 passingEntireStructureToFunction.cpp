#include <iostream>

using namespace std;

struct man{
    int a, b;
    char ch;
};

void f1(struct man *p) {
    cout << p->a << endl;
    cout << p->b << endl;
    cout << p->ch << endl;
}

int main() {

    struct man Abeer;
    Abeer.a = 56;
    Abeer.b = 85;
    Abeer.ch = 'Q';

    f1(&Abeer);

    return (0);
}
