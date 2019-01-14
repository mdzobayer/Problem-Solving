#include <iostream>

using namespace std;

int main()
{
    int i;
    /*for (i = 1000; i >= 1; --i){

        if ( i % 5 == 0){
            cout << endl;
        }
        cout << i << "\t";
    }*/
    int count = 0;
    for (i = 1000; i >= 1; --i){

        if ( count == 5){
            cout << endl;
            count = 0;
        }
        cout << i << "\t";
        count++;
    }

    return (0);
}
