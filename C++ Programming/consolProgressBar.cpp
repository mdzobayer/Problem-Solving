#include <iostream>
#include <time.h>
#include <cmath>
#include <windows.h>

using namespace std;

int main()
{
    srand(time(0));
    int x = 0;

    for(int i = 0; i<100; i++){
        int r = rand() % 1000;
        x++;
        cout << "\r" << x << "% completed." << flush;
        if(i < 43){
           Sleep(r/6);
        }else if(i > 43 && i < 74){
           Sleep(r/8);
        }else if(i < 98){
           Sleep(r/5);
        }else if(i > 97 && i != 99){
           Sleep(2000);
        }
    }

    cout << endl << endl << "Operation completed successfully.\n" << flush;
    return 0;
}
