class Solution {
    struct Node {
        bool isEnd;
        Node * link[27];

        Node() {
            isEnd = false;
            for (int i = 0; i < 27; ++i) {
                link[i] = nullptr;
            }
        }
    };

    Node * root;
    vector<vector<string>> result;
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new Node();

        for (int i = 0; i < products.size(); ++i) {
            if(products[i].front() == searchWord.front()) {
                insert(products[i]);
            }
        }

        vector<string> vt;
        for (int i = 0; i < searchWord.size(); ++i) {
            result.push_back(vt);
            findWordWith(searchWord.substr(0, i + 1), i);
        }

        clearMemory(root);

        return result;
    }

    void insert(string word) {
        Node * cursor = root;

        for (int i = 0; i < word.size(); ++i) {
            int charNumber = word[i] - 'a';
            if (cursor->link[charNumber] == nullptr) {
                cursor->link[charNumber] = new Node();
            }

            cursor = cursor->link[charNumber];
        }

        cursor->isEnd = true;
    }

    void findWordWith(string prefix, int suggestionIndex) {
        Node * cursor = root;

        for (int i = 0; i < prefix.size(); ++i) {
            int charNumber = prefix[i] - 'a';
            if (cursor->link[charNumber] == nullptr) return;
            cursor = cursor->link[charNumber];
        }

        if (cursor->isEnd) {
            if (result[suggestionIndex].size() >= 3) return;
            result[suggestionIndex].push_back(prefix);
        }

        for (int i = 0; i < 27; ++i) {
            if (cursor->link[i] != nullptr) {
                prefix += (char)(i + 'a');
                findWordEnd(prefix, cursor->link[i], suggestionIndex);
                prefix.pop_back();
            }
        }
    }

    void findWordEnd(string & prefix, Node * cursor, int suggestionIndex) {
        if (cursor->isEnd) {

            if (result[suggestionIndex].size() >= 3) return;

            result[suggestionIndex].push_back(prefix);

            //if (isFullText) return;
        }

        for (int i = 0; i < 27; ++i) {
            if (cursor->link[i] != nullptr) {
                prefix += (char)(i + 'a');
                findWordEnd(prefix, cursor->link[i], suggestionIndex);
                prefix.pop_back();
            }
        }
    }

    void clearMemory(Node * cursor) {
        if (cursor == nullptr) return;

        for (int i = 0; i < 27; ++i) {
            if (cursor->link[i] != nullptr) {
                clearMemory(cursor->link[i]);
            }
        }

        delete cursor;
    }
};