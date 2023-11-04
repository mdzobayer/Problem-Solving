/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr) return head;

        map<Node*, Node*> nodeMap;

        Node* cursor = head->next;
        Node* newHead = new Node(head->val);
        Node* newCursor = newHead;

        nodeMap[head] = newHead;

        while(cursor != nullptr) {
            newCursor->next = new Node(cursor->val);
            newCursor = newCursor->next;

            nodeMap[cursor] = newCursor;

            cursor = cursor->next;
        }

        cursor = head;
        newCursor = newHead;

        while(cursor != nullptr) {
            newCursor->random = nodeMap[cursor->random];

            cursor = cursor->next;
            newCursor = newCursor->next;
        }


        return newHead;
    }
};