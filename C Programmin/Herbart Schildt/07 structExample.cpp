#include <iostream>

using namespace std;

void displayWhile (char ch[40]) {
    int i = 0;
    while(ch[i] != '\0') {
        putchar(ch[i]);
        ++i;
    }
}
void Print (char ch[40]) {
    for (int i = 0; ch[i]; ++i) {
        putchar(ch[i]);
    }
}


int main() {
    struct {
        char name[30];
        char street[40];
        char city[20];
        char state[3];
        unsigned long int zip;
    }addr_info;
    gets(addr_info.name);
    for (int t = 0; addr_info.name[t]; ++t) {
        putchar(addr_info.name[t]);
    }
    cout << endl;
    int i = 0;
    while (!addr_info.name[i] == '\0') {
        putchar(addr_info.name[i]);
        ++i;
    }
    putchar('\n');

    char message[40] = "Hello World";
    displayWhile(message);
    putchar('\n');
    Print(message);
    struct {
        int a;
        float b;
    }x, y;

    x.a = 10;
    x.b = 25.26;
    y = x;
    cout << endl << y.b << endl;
    cout << y.a << endl;


    return (0);
}
