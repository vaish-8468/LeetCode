class MyStack {
public:
    queue<int> q1,q2;
    int top_=0;
    MyStack() {
       
    }
    
    void push(int x) {
        q1.push(x);
        top_=x;
        
    }
    
    int pop() {
      
            while(q1.size()>1){
                top_=q1.front();
                q2.push(top_);
                q1.pop();
            }
        //remove the top element from stack
        int pop_=q1.front();
        q1.pop();
        queue<int>temp;
        temp=q1;
        q1=q2;
        q2=temp; //swap the queue in order to avoid duplicates of q2 in q1
        return pop_;
           
    }
    
    int top() {
        return top_;
    }
    
    bool empty() {
        return q1.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */