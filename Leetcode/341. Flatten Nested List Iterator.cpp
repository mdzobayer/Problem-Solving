/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> numbers;
    int index = 0;

private:
    void getIntegers(vector<NestedInteger> &nested) {
        for (int i = 0; i < nested.size(); ++i) {
            if (nested[i].isInteger()) {
                numbers.push_back(nested[i].getInteger());
            }
            else {
                getIntegers(nested[i].getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        getIntegers(nestedList);
    }
    
    int next() {
        return numbers[index++];
    }
    
    bool hasNext() {
        return index < numbers.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */