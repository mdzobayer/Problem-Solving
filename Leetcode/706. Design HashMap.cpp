class MyHashMap {
    int keys[1000000 + 5];
    bool availableKeys[1000000 + 5];
public:
    MyHashMap() {
        memset(availableKeys, false, sizeof(availableKeys));
    }
    
    void put(int key, int value) {
        availableKeys[key] = true;
        keys[key] = value;
    }
    
    int get(int key) {
        if (!availableKeys[key]) return -1;

        return keys[key];
    }
    
    void remove(int key) {
        availableKeys[key] = false;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */