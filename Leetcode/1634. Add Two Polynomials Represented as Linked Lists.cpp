/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        unordered_map<int, int> powers;

        PolyNode* cursor = poly1;
        while(cursor != nullptr) {
            powers[cursor->power] += cursor->coefficient;
            cursor = cursor->next;
        }

        cursor = poly2;
        while(cursor != nullptr) {
            powers[cursor->power] += cursor->coefficient;
            cursor = cursor->next;
        }

        vector< pair<int,int> > list(powers.begin(), powers.end());
        sort(list.begin(), list.end(), greater<pair<int, int>>());

        PolyNode newHead;
        cursor = &newHead;

        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->second != 0) {
                cursor->next = new PolyNode(it->second, it->first);
                cursor = cursor->next;
            }
        }

        return newHead.next;
    }
};