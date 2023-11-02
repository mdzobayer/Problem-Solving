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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addList(l1, l2, false);
    }

    ListNode* addList(ListNode* l1, ListNode* l2, bool carry) {

        if (l1 == nullptr && l2 == nullptr) {
            if (carry) {
                return new ListNode(carry);
            }
            return nullptr;
        }

        int digit1 = 0, digit2 = 0, sum;

        if (l1 != nullptr) {
            digit1 = l1->val;
        }

        if (l2 != nullptr) {
            digit2 = l2->val;
        }

        sum = digit1 + digit2 + carry;
        carry = sum >= 10;
        sum = sum >= 10 ? sum % 10 : sum;

        ListNode * node = new ListNode(sum);

        node->next = addList(
            l1 != nullptr ? l1->next : nullptr,
            l2 != nullptr ? l2->next : nullptr,
            carry
        );

        return node;
    }
};