class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverseBit = 0, lastBit;
        int power = 31;
        while(n > 0) {
            lastBit = (n & 1);
            reverseBit += lastBit << power;

            n >>= 1;
            --power;
        }

        return reverseBit;
    }
};