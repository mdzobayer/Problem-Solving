#include <iostream>
#include <cstdio>
#include <sstream>
#include <stack>

using namespace std;
int main() {
    stack<long long int> st, output;
    int block, m, i, j;
    long long int num1, num2, carry;

    while(scanf("%d", &block) == 1) {
        for (j = 0; j < block; ++j) {
            while(!st.empty()) {
                st.pop();
            }
            while(!output.empty()) {
                output.pop();
            }
            scanf("%d", &m);
            for (i = 0; i < m; ++i) {
                scanf("%lld %lld", &num1, &num2);
                st.push(num1 + num2);
            }
            carry = 0;
            while(!st.empty()) {
                num1 = st.top();
                st.pop();
                num1 += carry;
                num2 = num1 % 10;
                num1 /= 10;
                carry = num1 % 10;
                output.push(num2);
            }
            stringstream ss;
            while(!output.empty()) {
                ss << output.top();
                output.pop();
            }
            cout << ss.str() << endl;
            if (j != (block - 1))
                putchar('\n');
        }
    }
    return (0);
}
/*
2

4
0 4
4 2
6 8
3 7

3
3 0
7 9
2 8

*/
