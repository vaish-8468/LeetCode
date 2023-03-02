class Solution {
public:
    
    
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> h(stones.begin(),stones.end());
        while(h.size()>=2){
            int y=h.top();
            h.pop();
            int x=h.top();
            h.pop();
            
            if(x==y){
                
            }
            else{
                h.push(y-x);
            }
        }
        if(!h.empty()){
            return h.top();
        }
        return 0;
    }
};