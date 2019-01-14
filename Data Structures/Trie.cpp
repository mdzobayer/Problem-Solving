#include <cstdio>
#include <cstring>

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

void insert (char * str, int len) {
    node * curr = root;
    for (int i = 0; i < len; ++i) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL) {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
    }
    curr->endMark = true;
}

bool search(char * str, int len) {
    node * curr = root;
    for (int i = 0; i < len; ++i) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL) {
            return false;
        }
        curr = curr->next[id];
    }
    return curr->endMark;
}

void del (node * curr) {
    for (int i = 0; i < 26; ++i) {
        if (curr->next[i])
            del(curr->next[i]);
    }
    delete (curr);
}

bool delWord(char * str, int len) {
    node * curr = root;
    for (int i = 0; i < len; ++i) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL) {
            return true;
        }
        curr = curr->next[id];
    }
    curr->endMark = false;
    return true;
}

int main() {

    printf("Enter number of words: ");
    root = new node();
    int numWord, i;
    scanf("%d", &numWord);

    for (i = 1; i <= numWord; ++i) {
        char str[50];
        scanf("%s", &str);
        insert(str, strlen(str));
    }
    printf("Enter number of Query : ");
    int query;
    scanf("%d", &query);
    for (i = 1; i <= query; ++i) {
        char str[50];
        scanf("%s", &str);
        if (search(str, strlen(str))) {
            puts("Found");
        }
        else {
            puts("Not Found");
        }
    }

    del(root);

    return (0);
}
