class StringIterator {
    string store;
    int index = 0, available = 0;
public:
    StringIterator(string compressedString) {
        store = compressedString;

        setAvailable(index + 1);

    }
    
    char next() {
        char ch = ' ';

        if (hasNext()) {
            ch = store[index];
            -- available;
        }

        return ch;
    }
    
    bool hasNext() {
        if (available > 0) return true;
        ++index;
        while(index < store.size() && store[index] >= '0' && store[index] <= '9') {
            ++ index;
        }

        setAvailable(index + 1);
        return available > 0;
    }

    void setAvailable(int idx) {
        available = 0;
        
        while(idx < store.size()) {
            if (store[idx] >= '0' && store[idx] <= '9') {
                available *= 10;
                available += store[idx] - '0';
            }
            else {
                break;
            }

            ++ idx;
        }
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */