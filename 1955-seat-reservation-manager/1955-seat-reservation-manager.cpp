class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> seatsMinHeap;
    SeatManager(int n) {
        for(int i=1; i<=n; i++){
            seatsMinHeap.push(i);
        }
    }
    
    int reserve() {
        int smallest = seatsMinHeap.top();
        seatsMinHeap.pop();
        return smallest;
    }
    
    void unreserve(int seatNumber) {
        seatsMinHeap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */