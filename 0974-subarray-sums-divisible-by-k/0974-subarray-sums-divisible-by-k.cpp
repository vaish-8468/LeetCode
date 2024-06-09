class Solution {
public:
    //dp[i][j]=sum;
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        
        // for(int i=0;i<nums.size();i++){
        //     long long sum_=0;
        //     for(int j=i;j<nums.size();j++){
        //         sum_+=nums[j];
        //         if(sum_%k==0){
        //             count++;
        //         }
        //     }
        //     cout<<count<<" ";
        // }
        unordered_map<int,int> mp;
        int n=nums.size();
        //saves remainder as key and with count of remainder encountered as a value
        int sum_=0;
        mp[0]=1; //by default, count is 1 for rem 0
        for(int i=0;i<n;i++){
            sum_+=nums[i];
            int rem=sum_%k;
            if(rem<0){
                rem=rem+k; //to make the remainder positive
                    }
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
                //if remainder is encountered then it signifies that subarray exists
            }
             mp[rem]++;
            
        }
        return count;
    }
};