class Solution {
public:
    
    bool solve(int i, vector<int>& dp, vector<int>& nums){
        //base case
        if(i==nums.size()){
            return true;
        }
        if(i==nums.size()-1){
            return false;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        bool res=false;
        //rule 1
        if( i+1<nums.size() && nums[i]==nums[i+1]){
             res |=solve(i+2,dp,nums); //OR operator
            //will become true if any of the subsequent states returns true
        }
        
        //rule 2
        if(i+2<nums.size() && nums[i]==nums[i+1] && nums[i]==nums[i+2]){
            res |=solve(i+3,dp,nums);
        }
        
        //rule 3
        
        if(i+2<nums.size() && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1){
             res |=solve(i+3,dp,nums);
        }
        
        
        return dp[i]=res;
    }
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(0,dp,nums);
    }
};