class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> seats; //min heap
    int smallestSeat;
    SeatManager(int n) {
        smallestSeat=1;
        //initialize the smallest seat as 1
        
    }
    
    int reserve() {
       if(!seats.empty()){
           int seatNum=seats.top();
           //initialize with the smallest seat and reserve it i.e remove
           //from the priority_queue
           seats.pop();
           return seatNum;
       }
        int seatNum=smallestSeat;
        smallestSeat++;
        return seatNum;
        
    }
    
    void unreserve(int seatNumber) {
    seats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */