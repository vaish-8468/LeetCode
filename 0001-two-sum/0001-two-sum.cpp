class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> st;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int s=target-nums[i];
            if(st.find(s)!=st.end()){
               ans.push_back(i);
                ans.push_back(st[s]);
                return ans;
            }
            st[nums[i]]=i;
        
    }
        return {};
    }
};