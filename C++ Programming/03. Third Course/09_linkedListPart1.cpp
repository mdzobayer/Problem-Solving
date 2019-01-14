#include <iostream>

using namespace std;
class Node {
public:
    string data;
    Node *next;

    Node(string aData, Node *aNext) {
        data = aData;
        next = aNext;
    }
    string getData() {
        return data;
    }
    Node *Next() {
        return next;
    }
};
int main() {
    /*
    A linked list is a series of nodes
    that are connected by pointers. So
    nodes have two fields.
        1. A data field
        2. Next field (that points to
           next field in the list)
    */

    return (0);
}
