#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    long long int number;

    stack<int> st;
    int i = 1;
    while(scanf("%llu", &number) && i <= 100 && number >= 0) {

        if(number == 0) {
            cout << 0 << endl;
            ++i;
            continue;
        }
        while(number != 0) {
            st.push(number % 3);
            number /= 3;
        }
        while(!st.empty()) {
            cout << st.top();
            st.pop();
        }
        cout << endl;
        ++i;
    }


    return (0);
}
