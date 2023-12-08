class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> highQ;
    priority_queue<int> lowQ;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        // add into low queue
        lowQ.push(num);

        // balance both queue
        highQ.push(lowQ.top());
        lowQ.pop();

        // memory resize
        if (lowQ.size() < highQ.size()) {
          lowQ.push(highQ.top());
          highQ.pop();
        }
    }
    
    double findMedian() {

        if (lowQ.size() > highQ.size()) {
          return lowQ.top();
        }

        int sum = lowQ.top() + highQ.top();

        return ((double)sum * 0.5);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */