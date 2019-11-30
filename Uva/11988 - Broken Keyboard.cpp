#include <bits/stdc++.h>

using namespace std;

struct Node {
    char ch;
    Node * nxt;
};

void PrintList(Node * ptr) {
    //cout << "Debug from printList" << endl;
    //printf("%c", ptr->ch);
    if (ptr->ch != '#') {
        putchar(ptr->ch);
    }

    if (ptr->nxt == NULL) return;

    ptr = ptr->nxt;
    PrintList(ptr);
}
void DeleteList(Node * ptr) {
    Node *ptr1;
    if (ptr->nxt != NULL) {
        ptr1 = ptr->nxt;
        DeleteList(ptr1);
    }

    delete ptr;
}

void solve(string s, int len) {
    Node * head, *tail, *cursor, *newObj;
    int i;
    bool flag;

    head = new Node;
    head->ch = '#';
    head->nxt = NULL;
    //printf("%c", head->ch);

    tail = head;

    cursor = head;

    flag = true;

    //cout << "Debug 1" << endl;
    //printf("%c", head->ch);
    for (i = 0; i < len; ++i) {
        if (s[i] == '[') {
            cursor = head;
            flag = false;
        }
        else if (s[i] == ']') {
            cursor = tail;
            flag = true;
        }
        else {
            //cout << "Debug " << s[i] << endl;
            newObj = new Node;
            newObj->ch = s[i];
            newObj->nxt = cursor->nxt;
            cursor->nxt = newObj;
            cursor = newObj;
            //cout << "Debug " << newObj->ch << endl;
            if (flag) {
                tail = cursor;
            }
        }
    }
    PrintList(head);
    //printf("%c", head->ch);
    putchar('\n');
    DeleteList(head);
    
}


int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    string s;
    int len;
    while(cin >> s) {
        len = s.size();
        solve(s, len);
    }

    return (0);
}