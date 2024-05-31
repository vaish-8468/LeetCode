class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //aim: TC=O(n)
            // SC=O(1)
        
        int n=nums.size();
        //n will always be even
        
        if(n==2){
            return nums; //corner case
        }
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            int key=nums[i];
            int j=i-1;
            
            while(j>=0 and key<nums[j]){
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=key;
        }
        
        bool first=false;
        bool last=false;
        
        if(nums[0]!=nums[1]){
            first=true;
        }
        if(nums[n-2]!=nums[n-1]){
            last=true;
        }
        
        
        for(int i=1;i<n-1;i++){
            if(nums[i-1]==nums[i] || nums[i]==nums[i+1]){
                continue;
            }
            ans.push_back(nums[i]);
            
        }
        
        if(ans.size()==1){
            if(first==true){
                ans.push_back(nums[0]);
            }
            else if (last==true){
                ans.push_back(nums[n-1]);
            }
        }
        
        else if(ans.size()==0){
            ans.push_back(nums[n-1]);
            ans.push_back(nums[0]);
        }
        
        return ans;
        
        
    }
};