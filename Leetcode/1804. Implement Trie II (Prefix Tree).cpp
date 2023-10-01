class Trie {

public:

    struct Node {
        int prefixCount, endCount;
        Node * next[28];
        Node() {
            for (int i = 0; i < 28; ++i) {
                next[i] = nullptr;
            }
            prefixCount = 0;
            endCount = 0;
        }
    };

    Node * root;

    Trie() {
        root = new Node();
    }

    ~Trie() {
        Node * cursor = root;

        
    }

    void clearMemory(Node * cursor) {
        for (int i = 0; i < 28; ++i) {
            if (cursor->next[i] != nullptr) {
                clearMemory(cursor->next[i]);
            }
        }

        delete cursor;
    }
    
    
    void insert(string word) {
        Node * cursor = root;
        
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (cursor->next[index] == nullptr) {
                cursor->next[index] = new Node();
            }
            cursor->prefixCount += 1;
            cursor = cursor->next[index];
        }
        cursor->endCount += 1;
        cursor->prefixCount += 1;
    }
    
    int countWordsEqualTo(string word) {
        int ans = 0;

        Node * cursor = root;
        bool found = true;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (cursor->next[index] == nullptr) {
                found = false;
                break;
            }
            cursor = cursor->next[index];
        }

        if (found) {
            ans = cursor->endCount;
        }

        return ans;
    }
    
    int countWordsStartingWith(string prefix) {
        int ans = 0;

        Node * cursor = root;
        bool found = true;
        for (int i = 0; i < prefix.size(); ++i) {
            int index = prefix[i] - 'a';
            if (cursor->next[index] == nullptr) {
                found = false;
                break;
            }
            cursor = cursor->next[index];
        }

        if (found) {
            ans = cursor->prefixCount;
        }

        return ans;
    }
    
    void erase(string word) {

        Node * cursor = root;
        bool found = true;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (cursor->next[index] == nullptr) {
                found = false;
                break;
            }
            cursor = cursor->next[index];
        }

        if (found) {
            cursor->endCount -= 1;

            cursor = root;
            for (int i = 0; i < word.size(); ++i) {
                int index = word[i] - 'a';
                if (cursor->next[index] == nullptr) {
                    found = false;
                    break;
                }
                cursor->prefixCount -= 1;
                cursor = cursor->next[index];
            }
            cursor->prefixCount -= 1;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */