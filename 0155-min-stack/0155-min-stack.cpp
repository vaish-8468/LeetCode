class MinStack {
public:
    
    int top_;
    vector<int> min_ele;
    int min_=INT_MAX;
    vector<int> arr;
    MinStack() {
     top_=-1;
    
    
    }
    
    void push(int val) {
    arr.push_back(val);
        top_++;
        min_ele.push_back(min(min_,val));
        min_=min_ele.at(top_);
        
        
    }
    
    void pop() {
        arr.pop_back();
        min_ele.pop_back();
        top_--;
        if(top_==-1){
            min_=INT_MAX;
        }
        else{
        min_=min_ele.at(top_);
        }
        
        
    }
    
    int top() {
        return arr.at(top_);
        
    }
    
    int getMin() {
        if(top_==-1){
            return min_;
        }
       return min_ele.at(top_);
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