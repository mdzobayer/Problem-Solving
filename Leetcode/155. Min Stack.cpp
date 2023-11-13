class MinStack {
    stack<int> stk;
    map<int, int> elementCount;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        elementCount[val] += 1;
    }
    
    void pop() {
        int val = stk.top();
        stk.pop();

        elementCount[val] -= 1;
        if (elementCount[val] == 0) {
            elementCount.erase(val);
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        auto it = elementCount.begin();
        return it->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */