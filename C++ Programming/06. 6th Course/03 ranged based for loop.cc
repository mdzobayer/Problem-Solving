#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector <int> vec;
    vec.push_back( 1 );
    vec.push_back( 2 );

    for (int& i : vec )
    {
        i++; // increments the value in the vector
    }
    for (int i : vec )
    {
        // show that the values are updated
        cout << i << " ";
    }
    cout << '\n';

    vector <int> vec1;
    vec1.push_back( 10 );
    vec1.push_back( 20 );

    for (const auto &i : vec1 )
    {
        cout << i << " ";
    }
}
