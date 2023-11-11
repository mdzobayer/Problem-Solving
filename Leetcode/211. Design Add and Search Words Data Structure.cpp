class WordDictionary {
    struct node {
        bool endMark;

        node * next[26];

        node() {
            endMark = false;
            for (int i = 0; i < 26; ++i) {
                next[i] = nullptr;
            }
        }
    };
    node * root;
public:
    WordDictionary() {
        root = new node();
    }

    void addWord(string word) {
        node * cursor = root;
        int i, nextIndex;

        for (i = 0; i < word.size(); ++i) {
            nextIndex = getNextIndex(word[i]);
            if (cursor->next[nextIndex] == nullptr) {
                cursor->next[nextIndex] = new node();
            }

            cursor = cursor->next[nextIndex];
        }
        cursor->endMark = true;
    }
    
    bool search(string word) {
        
        return search(root, word, 0);
    }

    bool search(node * cursor, const string & word, int index) {
        if (index == word.size()) return cursor->endMark;

        if (word[index] != '.') {
            int nextIndex = getNextIndex(word[index]);
            if (cursor->next[nextIndex] == nullptr) {
                return false;
            }
            return search(cursor->next[nextIndex], word, index + 1);
        }
        else {
            for (int i = 0; i < 26; ++i) {
                if (cursor->next[i] != nullptr && search(cursor->next[i], word, index + 1)) return true;
            }

            return false;
        }
    }

    int getNextIndex(const char & ch) {
        if (ch >= 'a' && ch <= 'z') return (ch - 'a');
        return 28;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */