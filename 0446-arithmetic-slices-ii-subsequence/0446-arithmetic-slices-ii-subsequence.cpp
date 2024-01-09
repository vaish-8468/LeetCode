class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        
        int res=0;
        
        unordered_map<long,int> mp[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long diff= (long)nums[i]-nums[j];
                int count_at_j=0;
                auto itr=mp[j].find(diff);
                if(itr!=mp[j].end()){
                    count_at_j=itr->second;
                    //fetch the frequency at jth index for the difference d
                }
                
                mp[i][diff]+=count_at_j+1; //update the frequencey corresponding to the diff
                res+=count_at_j; //count the contribution
            }
        }
        
        return res;
    }
};