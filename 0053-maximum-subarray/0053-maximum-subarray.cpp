class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_sum_here=0;
        int max_sum_so_far=INT_MIN;
        for(int i=0;i<n;i++){
            max_sum_here+=nums[i];
            if(max_sum_so_far<max_sum_here){
                max_sum_so_far=max_sum_here;
            }
            if(max_sum_here<0){
                max_sum_here=0;
            }
        }
        
        return max_sum_so_far;
        
    }
};