class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size()==1){ //for array of size one, doesn't matter whether it contains 1 or 0, one delete operation has to be performed
            return 0;
        }
        bool flag=false; //to keep a record if the delete operation has been execued
        int ans=0; //initisl size is 0
        
        for(int i=0;i<nums.size();i++){
            int left=-1; //initial left index of previous occurence of 0
            int right=nums.size(); //initial right index of next occurence of 0
            if(nums[i]==0){
                int j=i-1; //for back traversal
                int k=i+1; //for forward traversal
                while(j>-1){  //back traversal
                    if(nums[j]==0){
                        left=j;
                        break;
                    }
                    j--;
                }
                while(k<nums.size()){  //forward traversal
                    if(nums[k]==0){
                        right=k;
                        break;
                    }
                    k++;
                }
                ans=max((i-left-1)+(right-i-1),ans);  //storing the max subarray size
                flag=true; //marking the delete operation as done
    
            }
        }
        
        if(flag==false){ //if array does'nt contains any 0, still one delete opeartion has to be made
            return nums.size()-1;
        }
        return ans;
    }
};