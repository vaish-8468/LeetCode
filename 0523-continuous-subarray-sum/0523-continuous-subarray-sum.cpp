class Solution {
public:

    bool checkSubarraySum(vector<int>& nums, int k) {
        //brute force
        //TC=O(n*n)
        //SC=O(1)
        
        unordered_map<int,int> mp;
        int n=nums.size();
        //saves remainder as key and with index as a value
        int sum_=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum_+=nums[i];
            int rem=sum_%k;
            if(mp.find(rem)!=mp.end()){
                if((i-mp[rem])>=2 ){
                    return true;
                }
            }
                else{
                    mp[rem]=i;
                }
            
        }
        return false;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     long long sum_=nums[i];
        //     for(int j=i+1;j<n;j++){
        //         sum_+=nums[j];
        //         if(sum_%k==0){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        
        
        
     
    }
};