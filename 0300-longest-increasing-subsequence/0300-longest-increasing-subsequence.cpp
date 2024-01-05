class Solution {
public:
    int n;
    int LISHelperFunc(int idx, int prev_ind, vector<vector<int>>& dp, vector<int>& nums){
        if(idx==n){
            return 0;
        }
        if(dp[idx][prev_ind+1]!=-1){
            return dp[idx][prev_ind+1];
            
        }
        
        int len=0+LISHelperFunc(idx+1,prev_ind,dp,nums); //not take
        
        if(prev_ind==-1 || nums[idx]>nums[prev_ind]){
            len=max(len, 1+LISHelperFunc(idx+1,idx,dp,nums)); //take
        }
        
        return dp[idx][prev_ind+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev_ind=-1;
        n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return LISHelperFunc(0,prev_ind,dp,nums);
    }
};