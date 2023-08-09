class Solution {
public:
    bool foundPairs(vector<int>& nums, int difference, int p){
        //returns true of atleast p pairs of min difference d are found
        int countPairs=0;
        for(int i=0;i<nums.size()-1;){
            if(nums[i+1]-nums[i]<=difference){
            //count the pair
                //move onto the next pair
                countPairs++;
                i=i+2;
            }
            else{
                i++;
                //otherwise move onto the next index for pairing up
            }
        }
        
        return countPairs>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
   
        //applying binary search on the difference
        
        int ans=0;
        
        //sort the array 
        //for greedy approach+binary search
        
        sort(nums.begin(),nums.end());
        //eliminated max term since we have been asled to minimize the maximum differece, hence now we will have to check only for min difference since binary search will ignore big differnecs
        
        int left=0;
        int right=nums[nums.size()-1]-nums[0];
        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(foundPairs(nums,mid,p)==true){
                //if found atleast p pairs
                //check for min difference
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};