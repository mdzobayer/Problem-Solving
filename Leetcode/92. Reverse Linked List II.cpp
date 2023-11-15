/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* rightStop;
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (left == right) return head;

        int i = 0;
        ListNode *previousCursor = nullptr, *leftPrev, *leftCursor, *rightCursor, *cursor = head;

        while(cursor != nullptr) {
            ++i;
            if (i == left) {
                leftPrev = previousCursor;
                leftCursor = cursor;
            }
            else if (i == right) {
                rightCursor = cursor;
                break;
            }

            previousCursor = cursor;
            cursor = cursor->next;
        }

        rightStop = rightCursor->next;

        if (leftPrev == nullptr) {
            head = reverseConn(leftCursor, rightCursor->next);
        }
        else {
            leftPrev->next = reverseConn(leftCursor, rightCursor->next);
        }


        return head;
    }

    ListNode* reverseConn(ListNode* cursor, ListNode* previous) {
        if (cursor == nullptr || cursor == rightStop) return previous;

        ListNode* next = cursor->next;
        cursor->next = previous;

        return reverseConn(next, cursor);
    }
};