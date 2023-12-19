class LRUCache {
    map<int, int> cache;
    map<int, int> history;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    int index, capacity;
public:
    LRUCache(int capacity) {
        index = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        int ans = -1;
        if (cache.find(key) != cache.end()) {
            ans = cache[key];
            pq.push(make_pair(++index, key));
            history[key] = index;
        }

        return ans;
    }
    
    void put(int key, int value) {

        if (cache.find(key) == cache.end() && cache.size() >= capacity) {
            pair<int, int> aPair;
            while(true) {
                aPair = pq.top();
                pq.pop();
                if (aPair.first == history[aPair.second]) {
                    history.erase(aPair.second);
                    cache.erase(aPair.second);
                    break;
                }
            }
        }

        pq.push(make_pair(++index, key));
        history[key] = index;
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */