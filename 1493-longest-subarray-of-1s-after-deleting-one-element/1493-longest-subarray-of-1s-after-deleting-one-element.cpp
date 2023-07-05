class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size()==1){ //for array of size one, doesn't matter whether it contains 1 or 0, one delete operation has to be performed
            return 0;
        }
        bool flag=false;
        int ans=0;
        
        for(int i=0;i<nums.size();i++){
            int left=-1;
            int right=nums.size();
            if(nums[i]==0){
                int j=i-1;
                int k=i+1;
                while(j>-1){
                    if(nums[j]==0){
                        left=j;
                        cout<<left<<" ";
                        break;
                    }
                    j--;
                }
                while(k<nums.size()){
                    if(nums[k]==0){
                        right=k;
                        cout<<right;
                        break;
                    }
                    k++;
                }
                ans=max((i-left-1)+(right-i-1),ans);
                flag=true;
                cout<<endl;
            }
        }
        
        if(flag==false){
            return nums.size()-1;
        }
        return ans;
    }
};