//#include <iostream>
#include <cstring>
#include <cstdio>
//using namespace std;
//void *memchr(const void *buffer, int ch, size_t count);
int main() {

    char *p;

    p = memchr("bThis a is a test", 's', 14);
    printf(p);

    return (0);
}
