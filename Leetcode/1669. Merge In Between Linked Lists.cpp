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
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * cursor, * prevA, * prevB;
        int i = -1;

        cursor = list1;
        while(cursor != nullptr) {
            ++i;

            if (i == a - 1) {
                prevA = cursor;
            }
            if (i == b) {
                prevB = cursor;
            }

            cursor = cursor->next;
        }

        prevA->next = list2;

        cursor = list2;
        while(cursor->next != nullptr) {
            cursor = cursor->next;
        }

        cursor->next = prevB->next;

        return list1;
    }
};