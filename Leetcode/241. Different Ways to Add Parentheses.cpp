class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;

        if (expression.size() == 0) return results;
        if (expression.size() == 1) return vector<int> {stoi(expression)};

        if (expression.size() == 2 && isdigit(expression[0])) {
            return vector<int> {stoi(expression)};
        }

        for (int i = 0; i < expression.size(); ++i) {
            char currentChar = expression[i];

            if (isdigit(currentChar)) continue;

            vector<int> leftResults = diffWaysToCompute(expression.substr(0, i)), rightResults = diffWaysToCompute(expression.substr(i + 1));

            for (int leftValue : leftResults) {
                for (int rightValue : rightResults) {
                    int computedResult = 0;

                    switch(currentChar) {
                        case '+':
                            computedResult = leftValue + rightValue;
                            break;
                        case '-':
                            computedResult = leftValue - rightValue;
                            break;
                        case '*':
                            computedResult = leftValue * rightValue;
                            break;
                    }

                    results.push_back(computedResult);
                }
            }

        }

        return results;
    }
};