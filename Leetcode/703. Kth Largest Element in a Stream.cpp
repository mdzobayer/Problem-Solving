class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums)
            minHeap.push(num);
    }
    
    int add(int val) {
        if (minHeap.size() < k || minHeap.top() < val) {
            minHeap.push(val);

            while (minHeap.size() > k) minHeap.pop();
        }

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */