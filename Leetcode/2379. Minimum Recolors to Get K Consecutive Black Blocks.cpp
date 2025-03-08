class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int i, n, w, b, ans;
            w = b = 0;
            n = blocks.size();
            ans = n;
    
            for (i = 0; i < k; ++i) {
                if (blocks[i] == 'W') {
                    ++w;
                }
                else ++b;
            }
    
            ans = min(ans, w);
    
            for (i = k; i < n; ++i) {
                if (blocks[i] == 'W') {
                    ++w;
                }
                else ++b;
    
                if (blocks[i - k] == 'W') {
                    --w;
                }
                else --b;
    
                ans = min(ans, w);
            }
    
            return ans;
        }
    };