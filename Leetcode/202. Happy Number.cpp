class Solution {
public:
    bool isHappy(int n) {
        set<int> st;

        int lastDigit, sum;
        while(st.find(n) == st.end() && n > 1) {
            st.insert(n);
            sum = 0;

            while(n > 0) {
                lastDigit = n % 10;
                n /= 10;

                sum += (lastDigit * lastDigit);
            }
            n = sum;
        }

        return n == 1;
    }
};