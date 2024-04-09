/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        else if (head->next == nullptr || head == head->next) {
            head->next = new Node(insertVal);
            head->next->next = head;
            return head;
        }

        Node *prevCursor = head, *cursor = head->next;
        bool insertDone = false;

        while(true) {
            if (prevCursor->val <= insertVal && insertVal <= cursor->val) {
                prevCursor->next = new Node(insertVal);
                prevCursor = prevCursor->next;
                prevCursor->next = cursor;

                insertDone = true;
                break;
            }
            else if (prevCursor->val > cursor->val) {
                if (prevCursor->val <= insertVal || insertVal <= cursor->val) {
                    prevCursor->next = new Node(insertVal);
                    prevCursor = prevCursor->next;
                    prevCursor->next = cursor;

                    insertDone = true;
                    break;
                }
            }

            prevCursor = cursor;
            cursor = cursor->next;

            if (prevCursor == head) break;
        }

        if (!insertDone) {
            prevCursor->next = new Node(insertVal);
            prevCursor = prevCursor->next;
            prevCursor->next = cursor;

            insertDone = true;
        }

        return head;
    }
};