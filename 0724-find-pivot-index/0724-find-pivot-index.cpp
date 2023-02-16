class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i=0;
        int sum_l=0;
        int sum_r=accumulate(nums.begin(),nums.end(),0);
        while(i<nums.size()){
            sum_r-=nums[i];
            
            if(sum_l==sum_r){
                return i;
            }
            sum_l+=nums[i];
            i++;
        }
        return -1;
    }
       
};