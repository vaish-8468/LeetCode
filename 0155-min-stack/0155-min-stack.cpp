class MinStack {
public:
    
    int top_;
    vector<int> min_ele; //maintains the min_ele for every operation
    int min_=INT_MAX;  //initial min element value
    vector<int> arr;
    MinStack() {
     top_=-1;
    
    
    }
    
    void push(int val) {
    arr.push_back(val);
        top_++;
        min_ele.push_back(min(min_,val));  //for every peartion, store the min_element
        min_=min_ele.at(top_); //keep modifying the value of min_ simultaneously
        
        
    }
    
    void pop() {
        arr.pop_back();
        min_ele.pop_back();
        top_--;
        if(top_==-1){
            min_=INT_MAX;  //when the stack is empty
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
            return min_; //when the stack is empty
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