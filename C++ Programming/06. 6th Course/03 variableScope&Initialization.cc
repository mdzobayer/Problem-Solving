#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    /**
    const string s1 = "Some rather long string";

    const auto num_rs = std::count(std::begin(s1), std::end(s1), 'r');
    const vector <string> postfixes = { "1","22","333" };
    int total_length = 0;
    for (const auto &postfix : postfixes) {
        const auto appended = s1 + postfix;
        total_length += appended.size();
    }
    return num_rs + total_length;**/

    ///Advanced Initialization Cleanup

    const string s1 = "Some rather long string";

    const auto num_rs = count(begin(s1), end(s1), 'r');

    int total_length = 0;
    for (const auto &postfix : { "1","22","333" }) {
        const auto appended = s1 + postfix;
        total_length += appended.size();
    }
    return num_rs + total_length;

    /** Ranged Based For Loop Example
    vector<int> vec;
    vec.push_back( 10 );
    vec.push_back( 20 );

    for (const auto &i : vec )
    {
        cout << i << " ";
    }**/

}
