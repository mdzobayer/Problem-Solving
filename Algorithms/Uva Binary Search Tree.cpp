#include <bits/stdc++.h>
using namespace std;

/// Read & Write to File Short-Cut
#define fRead(x) freopen(x, "r", stdin)
#define fWrite(x) freopen(x, "w", stdout)
/// Data type Short-Cut
#define LLI long long int
#define ULL unsigned long long int
#define ff first
#define ss second
#define mk make_pair
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
/// Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node *root;
    void Insert(int data, Node *aNode);
    Node *Search(int data, Node *aNode);
    void preOrder(Node *aNode);
    void inOrder(Node *aNode);
    void postOrder(Node *aNode);
public:
    BST();
    void Insert(int data);
    Node *Search(int data);
    void preOrder();
    void inOrder();
    void postOrder();
};
//Scope resolution operator (::)
BST::BST() {
    root = NULL;
}
void BST::Insert(int data, Node *aNode) {
    if(data < aNode->data) {
        if(aNode->left != NULL)
            Insert(data, aNode->left);
        else {
            aNode->left = new Node(data);
            aNode->left->left = NULL;
            aNode->left->right = NULL;
        }
    }
    if(data >= aNode->data) {
        if(aNode->right != NULL) {
            Insert(data, aNode->right);
        }
        else {
            aNode->right = new Node(data);
            aNode->right->left = NULL;
            aNode->right->right = NULL;
        }
    }
}
void BST::Insert(int data) {
    if (root != NULL) {
        Insert(data, root);
    }
    else {
        root = new Node(data);
        root->left = NULL;
        root->right = NULL;
    }
}
Node* BST::Search(int data, Node *aNode) {
    if(aNode != NULL) {
        if(data == aNode->data) {
            return aNode;
        }
        else if(data < aNode->data) {
            return Search(data, aNode->left);
        }
        else {
            return Search(data, aNode->right);
        }
    }
    else {
        return NULL;
    }
}
Node* BST::Search(int data) {
    return Search(data, root);
}
void BST::preOrder() {
    preOrder(root);
}
void BST::preOrder(Node *aNode) {
    if (aNode != NULL) {
        cout << aNode->data << " ";
        preOrder(aNode->left);
        preOrder(aNode->right);
    }
}
void BST::inOrder() {
    inOrder(root);
}
void BST::inOrder(Node *aNode) {
    if (aNode != NULL) {
        inOrder(aNode->left);
        cout << aNode->data << " ";
        inOrder(aNode->right);
    }
}
void BST::postOrder() {
    postOrder(root);
}

void BST::postOrder(Node *aNode) {
    if (aNode != NULL) {
        postOrder(aNode->left);
        postOrder(aNode->right);
        printf("%d\n",aNode->data);
    }
}

int main() {
    FastRead
    //fRead("in.txt");
    BST *btree = new BST;

    int n;
    while(scanf("%d", &n) == 1) {
        btree->Insert(n);
    }
    btree->postOrder();

    return (0);
}
