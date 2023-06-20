class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
         int n=nums.size();
        vector<int> avg(n,-1);                  //initially we've initialized the vector with -1
        int p=(2*k)+1;                               //the subarray will be of lengt 2*k+1 as there will be i-k+i+k+1 elements in each subarray
        if(k==0){  //basecase if k<nums size then the whole original vector will be returned as it is
            return nums;
        }
        
        if(nums.size()<2*k){  //basecase if k>nums size then we can't really calculate the avg since here is only one element for it to satisfy the condition
            return avg;
        }
        
                                             //we'll use deque as this can help us to do this ques in TC=O(n) with SC=O(n)
        long long sum=0;
        int m=0;                        //for recording the subarray size
        int l=0;                                //for removing the lements from the back
        for(int i=0;i<n;i++){
                                //we'll keep adding the lements until the subarray length is statisfied
            sum+=nums[i];
                       //we'll keep a record of the sum which will help us to calculate avg for each case
            if(i-l+1==p){
                avg[i-k]=ceil(sum/p); //whenever array size becomes full, we'll calcuate the avg and store it
                // cout<<i-k<<" "<<avg[i-k]<<" "<<sum<<endl;
                sum-=nums[l];
                l++;                    //we'll make space for the other elements to get included in the sub array
                                             //hence we'll keep removing from the front as the array gets full to make more space
            }
        }
        
       return avg;
    }
};