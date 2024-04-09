class FirstUnique {
    int index;
    vector<int> vt;
    unordered_map<int, int> counts;
public:
    FirstUnique(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            vt.push_back(nums[i]);
            ++ counts[nums[i]];
        }
        index = 0;
    }
    
    int showFirstUnique() {
        while(index < vt.size()) {
            int cnt = counts[vt[index]];
            if (cnt == 1) return vt[index];
            ++index;
        }

        return -1;
    }
    
    void add(int value) {
        vt.push_back(value);
        ++ counts[value];
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */