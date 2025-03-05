class Solution {
    public:
        long long coloredCells(int n) {
            long long ans = 1;
            int newCell = 4;
    
            while(--n) {
                ans += newCell;
                newCell += 4;
            }
    
            return ans;
        }
    };