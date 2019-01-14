#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){

    double pi = 3.14158674684654;
    printf("%f\n",pi);
    printf("%10f\n",pi);
    printf("%10.8f\n",pi);

    int number = -100;
    printf("%d\n",number);
    printf("%15d\n",number);
    printf("%+10d",number);
    printf("%10d",number);
    printf("\n%s\n","Hello, World");
    string hello = "Hello, World";
    cout << hello << endl;

    return (EXIT_SUCCESS);
};
