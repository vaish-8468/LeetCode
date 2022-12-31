class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp;
        for(auto x:nums){
            for(auto y:nums){
                ++mp[x&y];
            }
        }
        
        for(auto x:nums){
            for(auto y:mp){
                if((y.first&x)==0){
                    ans+=y.second;
                }
            }
        }
            
        
        return ans;
        
    }
};