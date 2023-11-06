class SeatManager {
    priority_queue<int,vector<int>, greater<int>> minheap;
    int seat;
public:
    SeatManager(int n) {
        // for(int i=1;i<=n;i++) minheap.push(i);
        seat=1;
    }
    
    int reserve() {
        if(minheap.size()){
            int res= minheap.top();
            minheap.pop();
            return res;
        }
        seat++;
        return seat-1;
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