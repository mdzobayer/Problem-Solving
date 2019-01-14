
#include <iostream>

using namespace std;

int main()
{

    /*int *pointer, n, temp;
    cin >> n;

    pointer = new(nothrow) int[n];

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        *(pointer + i) = temp;
    }

    for (int j = 0; j < n; ++j)
        if (*(pointer + j) % 2 == 0)
            cout << "even" << endl;
        else
            cout << "odd" << endl;

    delete[] pointer;*/

    int n, i, num;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        scanf("%d",&num);
        if (num % 2 == 0)
            cout << "even\n";
        else
            cout << "odd\n";
    }

    return (0);
}
