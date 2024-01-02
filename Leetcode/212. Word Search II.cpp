class Solution {
    struct Node {
        bool isEnd;
        Node * link[30];
    };

    Node * root;
    int m, n;
    bool visited[13][13];
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    unordered_map<string, bool> hashMap;
    vector<string> ans;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // set range
        m = board.size();
        n = board[0].size();
        
        // Init trie
        root = new Node();
        root->isEnd = false;
        for (int i = 0; i < 30; ++i) {
            root->link[i] = nullptr;
        }

        // Insert queries into trie
        for (int i = 0; i < words.size(); ++i) {
            insert(words[i]);
            hashMap[words[i]] = false;
        }

        findWordsOnMatrix(board);

        return ans;
    }

    void findWordsOnMatrix(vector<vector<char>>& board) {
        int i, j;

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                memset(visited, false, sizeof(visited));
                string prefix = "";
                generateWordWithBacktrack(board, prefix, i, j);
            }
        }
    }

    void generateWordWithBacktrack(vector<vector<char>>& board, string & prefix, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (visited[x][y]) return;

        prefix.push_back(board[x][y]);
        visited[x][y] = true;

        if (startsWith(prefix)) {
            
            for (int i = 0; i < 4; ++i) {
                generateWordWithBacktrack(board, prefix, x + dir[i][0], y + dir[i][1]);
            }

            if (search(prefix)) {
                if (!hashMap[prefix]) {
                    hashMap[prefix] = true;
                    ans.push_back(prefix);
                }
            }
        }

        visited[x][y] = false;
        prefix.pop_back();
    }

    void insert(const string & word) {
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
    
    bool search(const string & word) {
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

    bool startsWith(const string & prefix) {
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