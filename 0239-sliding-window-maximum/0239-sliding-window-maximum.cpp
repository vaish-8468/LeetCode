class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque<int> q;
        if(n==1){
            ans.push_back(nums[0]);
            return ans;
        }
        for(int i=0;i<n;i++){
                if(q.empty()){
                    q.push_back(i);
                }
                else{
                    while(!q.empty() && nums[q.back()]<nums[i]){
                        q.pop_back();
                    }
                    q.push_back(i);
                    if(q.front()==i-k){
                        q.pop_front();
                    }
                }
                
            
            if(i>=k-1)
                ans.push_back(nums[q.front()]);
            
        }
        return ans;
    }
};