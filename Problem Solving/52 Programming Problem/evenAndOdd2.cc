#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    char str1[128], str2[7];
    int lastValue, length;
    unsigned int count;
    cin >> count;
    getchar();
    for(int i = 0; i < count; i++){
        gets(str1);
        length = strlen(str1);
        strncpy(str2, str1 + (length - 1), 1);
        lastValue = atoi(str2);
        if (lastValue % 2 == 0){
            cout << "even" << endl;
        }
        else {
            cout << "odd" << endl;
        }
    }

    return (0);
}
