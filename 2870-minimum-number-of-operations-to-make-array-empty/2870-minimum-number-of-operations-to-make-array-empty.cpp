class Solution {
public:
    int minOperations(vector<int>& nums) {
        //GREEDY Problem
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int minOps=0;
        
        for(auto &x: mp){
            int frequency=x.second;
            
            if(frequency==1){
                //array can never be made empty
                return -1;
            }
            
            minOps+=ceil((double)frequency/3); //greedy approach
            //gathering in group of 3 will cost less number of opeartions
            //input to ceil() should always be of type "double"
            
        }
        
        return minOps;
        
    }
};