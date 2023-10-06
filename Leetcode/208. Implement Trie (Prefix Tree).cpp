class Trie {
    struct Node {
        bool isEnd;
        Node * link[30];
    };

    Node * root;
public:
    Trie() {
        root = new Node();
        root->isEnd = false;
        for (int i = 0; i < 30; ++i)
            root->link[i] = nullptr;
    }
    
    void insert(string word) {
        Node * cursor;
        cursor = root;

        int character;

        for (int i = 0; i < word.size(); ++i) {
            character = word[i] - 'a';

            if (cursor->link[character] == nullptr) {
                cursor->link[character] = new Node();
            }
            cursor = cursor->link[character];
        }

        cursor->isEnd = true;
    }
    
    bool search(string word) {
        Node * cursor;
        cursor = root;

        int character;

        for (int i = 0; i < word.size(); ++i) {
            character = word[i] - 'a';

            if (cursor->link[character] == nullptr) {
                return false;
            }
            cursor = cursor->link[character];
        }

        return cursor->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node * cursor;
        cursor = root;

        int character;

        for (int i = 0; i < prefix.size(); ++i) {
            character = prefix[i] - 'a';

            if (cursor->link[character] == nullptr) {
                return false;
            }
            cursor = cursor->link[character];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */