class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> extraGas;
        int gasNeed = 0, maxNetGas = 0, index;
        for (int i = 0; i < gas.size(); ++i) {
            extraGas.push_back(gas[i] - cost[i]);
            gasNeed += extraGas[i];

            if (extraGas[i] > maxNetGas) {
                maxNetGas -= extraGas[i];
                index = i;
            }
        }

        if (gasNeed < 0) return -1;

        gasNeed = 0; 
        index = 0;
        int available = 0;
        
        for (int i = 0; i < extraGas.size(); ++i) {
            available += extraGas[i];

            if (available < 0) {
                available = 0;
                index = i + 1;
            }
        }

        return index;
    }
};