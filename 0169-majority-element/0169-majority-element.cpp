class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        int ans=-1;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            
            if(mp[nums[i]]>floor(nums.size()/2)){
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};