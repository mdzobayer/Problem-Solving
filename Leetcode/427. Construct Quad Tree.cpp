/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    bool isSame(vector<vector<int>>& grid, int x, int y, int len) {
        int i, j;
        for (i = x; i < x + len; ++i) {
            for (j = y; j < y + len; ++j) {
                if (grid[i][j] != grid[x][y])
                    return false;
            }
        }

        return true;
    }

    Node* solve(vector<vector<int>>& grid, int x, int y, int len) {
        if (isSame(grid, x, y, len)) {
            return new Node(grid[x][y], true);
        }

        Node * root = new Node(grid[x][y], false);

        int newLen = len / 2;
        root->topLeft = solve(grid, x, y, newLen);
        root->topRight = solve(grid, x, y + newLen, newLen);
        root->bottomLeft = solve(grid, x + newLen, y, newLen);
        root->bottomRight = solve(grid, x + newLen, y + newLen, newLen);

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};