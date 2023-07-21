class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> LISlen(n,1); //initially all LIS length will be 1
        vector<int> LIScount(n,1); //initially  occurence of each LIS will be 1 only
        
        int ans=0;
        
        int maxlen=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    
                    if(LISlen[i]==LISlen[j]+1){ //if value already exists
                        LIScount[i]+=LIScount[j]; //add the freq of last LISlen into the current one
                    }
                    else if(LISlen[i]<LISlen[j]+1){ //if updated value doesn't exist 
                        LIScount[i]=LIScount[j]; //count the frequency of the last LISlen
                        LISlen[i]=LISlen[j]+1; //then update the value
                    }
                    
                }
            
            }
                maxlen=max(maxlen,LISlen[i]);
        }
        
        //sum the frequency of all occurence/variations of max LISlen
        for(int i=0;i<n;i++){
            if(LISlen[i]==maxlen){
                ans+=LIScount[i];
            }
        }
        return ans;
        
    }
};