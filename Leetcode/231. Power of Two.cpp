class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long int x = 1;
        
        while(x < n) {
            x <<= 1;
        }
        
        return x == n;
    }
};