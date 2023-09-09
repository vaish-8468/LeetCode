class Solution {
public:

    int possibleCombi(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target==0){
            return 1;
        }
            
        if(target<0 || ind>=nums.size()){
            return 0;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        
        int take=possibleCombi(0,target-nums[ind],nums,dp);
        int not_take=possibleCombi(ind+1,target,nums,dp);
        
        return dp[ind][target]=take+not_take; 
       
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,-1));

        return possibleCombi(0,target,nums,dp);
    
    
        
    }
};