class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascalRow;
        vector<vector<int>> pascalTriangle;

        pascalTriangle.push_back(pascalRow);
        pascalTriangle[0].push_back(1);

        for (int i = 1; i <= rowIndex; ++i) {
            pascalTriangle.push_back(pascalRow);

            for (int j = 0; j <= i; ++j) {
                int sum = 0;
                if (j > 0) {
                    sum += pascalTriangle[i - 1][j - 1];
                }

                if (j < i) {
                    sum += pascalTriangle[i - 1][j];
                }

                pascalTriangle[i].push_back(sum);
            }
        }

        return pascalTriangle[rowIndex];
        
    }
};