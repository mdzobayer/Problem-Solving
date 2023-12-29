class Solution {
public:
    int SIZE = 10;
    int findSubBox(int row, int column) {
        if (row < 3) {
            
            if (column < 3) {
                return 0;
            } else if (column < 6) {
                return 1;
            } else {
                return 2;
            }
            
        } else if (row < 6) {
            if (column < 3) {
                return 3;
            } else if (column < 6) {
                return 4;
            } else {
                return 5;
            }
        } else {
            if (column < 3) {
                return 6;
            } else if (column < 6) {
                return 7;
            } else {
                return 8;
            }
        }
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool validSubBoxes[SIZE][SIZE];
        bool validRows[SIZE][SIZE];
        bool validColumns[SIZE][SIZE];
        
        memset(validSubBoxes, false, sizeof(validSubBoxes));
        memset(validRows, false, sizeof(validRows));
        memset(validColumns, false, sizeof(validColumns));
        
        int i, j, digit, subBoxNumber;
        
        for (i = 0; i < 9; ++i) {
            for (j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    digit = (int)board[i][j] - '0';
                    
                    subBoxNumber = findSubBox(i, j);
                    
                    if (validSubBoxes[subBoxNumber][digit]) {
                        return false;
                    }
                    validSubBoxes[subBoxNumber][digit] = true;
                    
                    if (validRows[i][digit]) {
                        return false;
                    }
                    validRows[i][digit] = true;
                    
                    if (validColumns[j][digit]) {
                        return false;
                    }
                    validColumns[j][digit] = true;
                }
            }
        }
        
        
        return true;
    }
};