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
    int pairSum(ListNode* head) {
        ListNode * cursor = head;
        int maxPair = 0, i, n = 0, sum;

        vector<int> numbers;

        while(cursor != nullptr) {
            ++n;
            numbers.push_back(cursor->val);

            cursor = cursor->next;
        }

        int halfLenght = n / 2;
        for (i = 0; i < halfLenght; ++i) {
            sum = numbers[i] + numbers[n - 1 - i];
            if (sum > maxPair) {
                maxPair = sum;
            }
        }

        return maxPair;
    }
};