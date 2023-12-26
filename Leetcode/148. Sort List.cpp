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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *left, *right, *mid = findMid(head);
        left = sortList(head);
        right = sortList(mid);
        return mergeList(left, right);
    }

    ListNode * mergeList(ListNode * list1, ListNode * list2) {
        ListNode head(0);
        ListNode * cursor = &head;

        while(list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                cursor->next = list1;
                list1 = list1->next;
            }
            else {
                cursor->next = list2;
                list2 = list2->next;
            }
            cursor = cursor->next;
        }

        if (list1 != nullptr) {
            cursor->next = list1;
        }
        else {
            cursor->next = list2;
        }

        return head.next;
    }

    ListNode* findMid(ListNode * head) {
        ListNode * fast = head, * slow = nullptr, * mid;

        while(fast != nullptr && fast->next != nullptr) {
            if (slow == nullptr) {
                slow = head;
            }
            else {
                slow = slow->next;
            }
            fast = fast->next->next;
        }

        mid = slow->next;
        slow->next = nullptr;
        
        return mid;
    }
};