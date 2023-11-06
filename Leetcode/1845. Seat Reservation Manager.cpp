class SeatManager {
    map<int, bool> availableSeat;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            availableSeat.insert({i, true});
        }
    }
    
    int reserve() {
        int smallest = (availableSeat.begin())->first;
        availableSeat.erase(smallest);

        return smallest;
    }
    
    void unreserve(int seatNumber) {
        availableSeat.insert({seatNumber, true});
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */