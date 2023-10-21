class RandomizedSet {
    set<int> st;
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if (st.find(val) == st.end()) {
            st.insert(val);
            return true;
        }
        else return false;
    }
    
    bool remove(int val) {
        if (st.find(val) != st.end()) {
            st.erase(val);
            return true;
        }
        else return false;
    }
    
    int getRandom() {
        int setSize = st.size();

        int random = rand() % setSize;

        set<int>::iterator it;
        int i;
        for (it = st.begin(), i = 0; i < random; ++i, ++it) {

        }

        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */