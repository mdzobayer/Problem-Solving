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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector< vector<int> > spiralMatrix(m, vector<int>(n, -1));

        ListNode* cursor = head;

        int minRow = 0, minColumn = 0, maxRow = m - 1, maxColumn = n - 1, i;
        while(cursor != nullptr) {
            
            // top row
            for (i = minColumn; i <= maxColumn && cursor != nullptr; ++i) {
                spiralMatrix[minRow][i] = cursor->val;
                cursor = cursor->next;
            }
            ++ minRow;

            // right column
            for (i = minRow; i <= maxRow && cursor != nullptr; ++i) {
                spiralMatrix[i][maxColumn] = cursor->val;
                cursor = cursor->next;
            }
            -- maxColumn;

            // bottom row
            for (i = maxColumn; i >= minColumn && cursor != nullptr; --i) {
                spiralMatrix[maxRow][i] = cursor->val;
                cursor = cursor->next;
            }
            -- maxRow;

            // left column
            for (i = maxRow; i >= minRow && cursor != nullptr; --i) {
                spiralMatrix[i][minColumn] = cursor->val;
                cursor = cursor->next;
            }
            ++ minColumn;
        }

        return spiralMatrix;
    }
};