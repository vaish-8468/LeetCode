class Solution {
public:
    
    void countPermute(int ind, vector<int>& nums, vector<vector<int>>& ans, int n){
        if(ind==n){// if the pointer reaches the last+1 element, count the permutation
            ans.push_back(nums);
            return;
        }
        
        //run a loop for every ind element till n-1 and keep swapping it with others and count the permutation
        for(int i=ind;i<n;i++){
            swap(nums[ind],nums[i]);
            countPermute(ind+1,nums,ans,n); //call recursively in order to generate permutations
            swap(nums[ind],nums[i]); //to retrieve original nums while backtracking
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
    int n=nums.size();
        vector<int> v;
        vector<vector<int>> ans;
        countPermute(0,nums,ans,n);
        return ans;
    }
};