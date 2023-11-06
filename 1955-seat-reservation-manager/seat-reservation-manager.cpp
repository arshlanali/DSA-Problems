class SeatManager {
    priority_queue<int,vector<int>, greater<int>> minheap;
public:
    SeatManager(int n) {
        for(int i=1;i<=n;i++) minheap.push(i);
    }
    
    int reserve() {
        int res= minheap.top();
        minheap.pop();
        return res;
    }
    
    void unreserve(int x) {
        minheap.push(x);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */