class Solution {
    string binaryValueOfA, binaryValueOfB, binaryValueOfC;
public:
    int minFlips(int a, int b, int c) {
        
        binaryValueOfA = getBinaryRepresentation(a); 
        binaryValueOfB = getBinaryRepresentation(b);
        binaryValueOfC = getBinaryRepresentation(c);

        int length = binaryValueOfA.size();
        length = max((int)binaryValueOfB.size(), length);
        length = max((int)binaryValueOfC.size(), length);

        if (binaryValueOfA.size() < length) {
            string str(length - binaryValueOfA.size(), '0');
            binaryValueOfA = str + binaryValueOfA;
        }

        if (binaryValueOfB.size() < length) {
            string str(length - binaryValueOfB.size(), '0');
            binaryValueOfB = str + binaryValueOfB;
        }

        if (binaryValueOfC.size() < length) {
            string str(length - binaryValueOfC.size(), '0');
            binaryValueOfC = str + binaryValueOfC;
        }

        return solve(length - 1);

    }

    int solve(int index) {
        if (index < 0) return 0;


        bool bit1, bit2, bit3;
        bit1 = binaryValueOfA[index] - '0';
        bit2 = binaryValueOfB[index] - '0';
        bit3 = binaryValueOfC[index] - '0';

        bool orResult = bit1 | bit2;
        int flipNeed = 0;
        if (orResult == bit3) {
            // No flip needed
            flipNeed = 0;
        }
        else {
            if (bit3 == true) {
                // 1 flip needed
                flipNeed = 1;
            }
            else {
                if (bit1 && bit2) {
                    flipNeed = 2;
                }
                else {
                    flipNeed = 1;
                }
            }
        }

        return flipNeed + solve(index - 1);
    }

    string getBinaryRepresentation(int x) {
        string value = "";

        while(x > 0) {
            char bit = '0';
            if (x & 1) bit = '1';
            x >>= 1;

            value += bit;
        }

        reverse(value.begin(), value.end());

        return value;
    }
};