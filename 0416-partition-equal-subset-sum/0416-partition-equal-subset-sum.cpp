class Solution {
public:
    bool checkSubsets(int index, vector<int>& nums, vector<vector<int>>& dp, int target){
        if(index==0){
            if(nums[index]==target){
                //just single element present and of equal magnitude
                return 1;
            }
            else{
                return 0;
            }
        }
        if(target==0){
            return 1;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        
        bool take=false;
        //insitially assumed to be false such that if target <nums[index], elemnt will be skipped
        if(target>=nums[index]){
            take=checkSubsets(index-1,nums,dp,target-nums[index]);
        }
        
        bool notTake=checkSubsets(index-1,nums,dp,target);
        
        return dp[index][target]=take|notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
            //not possible
        }
        
        vector<vector<int>> dp(nums.size(),vector<int>(sum,-1));
        //dp states are index and atrget sum
        
        //otherwise check for the existence of any one subset which gives sum s/2 such that the other subset will bound to give the other s/2 result
        return checkSubsets(nums.size()-1,nums,dp,sum/2);
    }
};