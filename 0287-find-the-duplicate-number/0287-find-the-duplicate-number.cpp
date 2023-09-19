class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        
       
        
        int slow=nums[0];
        int fast=nums[0];
        
        slow=nums[slow];
        fast=nums[nums[fast]];
        
        
        //check if the cycle exists
        //move fast by two steps
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        
        //find the starting point of the cycle
        //because of the existence of the duplicate, the cycle exists
        slow=nums[0];
        
        
        //move the pointers by one step now 
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        
        return fast; //both slow and fast will be same
        
        
    }
};