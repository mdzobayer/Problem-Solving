class MovingAverage {
    int total, sliderSide;
    deque<int> dq;
public:
    MovingAverage(int size) {
        total = 0;
        sliderSide = size;
    }
    
    double next(int val) {
        dq.push_back(val);
        total += val;

        if (dq.size() > sliderSide) {
            total -= dq.front();
            dq.pop_front();
        }

        return (double)total / (int)dq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */