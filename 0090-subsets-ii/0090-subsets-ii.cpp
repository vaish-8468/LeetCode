class Solution {
public:
    
    void subset(int ind, vector<int>& nums,vector<int>& v, vector<vector<int>>& ans ){
        ans.push_back(v);
        
        for(int i=ind;i<nums.size();i++){
            
            if(i>ind && nums[i]==nums[i-1]){
                //in order to avoid generating duplicate combinations 
                continue;
            }
            v.push_back(nums[i]); //take
            subset(i+1,nums,v,ans); //keep incrementing index until all the elements are covered
            v.pop_back(); //do-not take
            //automatically clears the vector
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end()); //sort the vector first
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        subset(0,nums,v,ans);
        return ans;
    }
};