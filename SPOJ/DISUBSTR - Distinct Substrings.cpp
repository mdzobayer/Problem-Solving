#include <bits/stdc++.h>

using namespace std;
#define MAX 4005


int uniqueStr;

/// Suffix array function
struct subStr {
    int tupl[2], index;

    bool operator < (const subStr &tmp) const {
        if(this->tupl[0] != tmp.tupl[0]) {
            return this->tupl[0] < tmp.tupl[0];
        }
        return this->tupl[1] < tmp.tupl[1];
    }
};

/// Trie functions

struct node {
    bool endMark;   /// End of a word
    node * next[26 + 2]; /// Link to other word
    /// Constructor to initialize the variable/object
    node() {
        endMark = false;
        for (int i = 0; i < 26; ++i) {
            next[i] = NULL;
        }
    }
} * root;

void insert (const string & str, int len) {
    //cout << "Called with : " << str << endl;
    node * curr = root;
    for (int i = 0; i < len; ++i) {
        int id = str[i] - 'A';
        //cout << "Debug 3" << endl;
        if (curr->next[id] == NULL) {
            ++uniqueStr;
            //cout << "Debug 4" << endl;
            curr->next[id] = new node();
        }
        //cout << "Debug 5" << endl;
        curr = curr->next[id];
    }
    curr->endMark = true;
}

//bool search(char * str, int len) {
//    node * curr = root;
//    for (int i = 0; i < len; ++i) {
//        int id = str[i] - 'a';
//        if (curr->next[id] == NULL) {
//            return false;
//        }
//        curr = curr->next[id];
//    }
//    return curr->endMark;
//}

void del (node * curr) {
    for (int i = 0; i < 26; ++i) {
        if (curr->next[i] != NULL)
            del(curr->next[i]);
    }
    delete (curr);
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, len, t;

    subStr arr[MAX];
    int Rank[18][MAX], step, i, j, n, jump;

    root = new node();
    string text, s;
    cin >> test;
    cin.ignore();
    for (t = 0; t < test; ++t) {
        cin >> text;
        //cout << "Input: " << text << endl;
        n = text.size();
        uniqueStr = 0;

        /// Building Suffix
        // Rank suffixes according to 1st character
        for (j = 0; j < n; ++j) {
            Rank[0][j] = text[j];
            memset(arr[j].tupl, 0, sizeof(arr[j].tupl));
        }
        //cout << "Debug 1" << endl;
        for (step = 1, jump = 1; jump < n; ++step, jump <<= 1) {
            for (j = 0; j <= n; ++j) {
                arr[j].index = j;
                arr[j].tupl[0] = Rank[step - 1][j];
                arr[j].tupl[1] = j + jump < n ? Rank[step - 1][j + jump] : -1;
            }
            sort(arr, arr + n);
            Rank[step][arr[0].index] = 0;
            for (j = 1; j < n; ++j) {
                if((arr[j].tupl[0] == arr[j-1].tupl[0]) && (arr[j].tupl[1] == arr[j-1].tupl[1]))
                    Rank[step][arr[j].index] = Rank[step][arr[j-1].index];
                else Rank[step][arr[j].index] = j;
            }
        }
        //cout << "debug 1" << endl;
        for (i = 0; i < n; ++i) {
            s = text.substr(arr[i].index);
            len = s.size();
            //cout << "Suffix: " << s << endl;
            insert(s, len);
        }

        cout << uniqueStr << endl;

        del(root);
        root = new node();
    }

    del(root);

    return (0);
}
