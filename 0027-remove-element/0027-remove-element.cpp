class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        if(n==0){
            return n;
        }
        int i=0;
        int j=n-1;
        int count=0;
        
        while(i<j){
            if(nums[i]==val){
                while(nums[j]==val && j>0 && i<j){
                    j--;
                }
                cout<<j<<" ";
                swap(nums[i],nums[j]);
                j--;
                i++;  
            }
            else{
                i++;
            }
           
        }
        
        for(int m=n-1;m>=0;m--){
            if(nums[m]!=val){
                break;
            }
            count++;
        }
        
        if(count==n){
            return 0;
        }
      return nums.size()-count;  
    }
};