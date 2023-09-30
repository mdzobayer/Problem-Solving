class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> st;
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1500; ++i) {
            pq.push(i);
            st.insert(i);
        }
    }
    
    int popSmallest() {
        int item = pq.top();
        pq.pop();

        set<int>::iterator it = st.find(item);
        if (it != st.end()) {
            st.erase (it);
        }

        return item;
    }
    
    void addBack(int num) {
        set<int>::iterator it = st.find(num);
        if (it == st.end()) {
            pq.push(num);
            st.insert(num);
        } 
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */