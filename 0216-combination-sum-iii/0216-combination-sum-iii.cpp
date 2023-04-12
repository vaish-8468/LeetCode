class Solution {
public:
    
    void subsets(int num, int k,int n, vector<int>& v, vector<vector<int>>& ans){
        
        if(n==0){
         //   base case when n becomes 0
            if(k==0){
                // k is written in if statement so as to return the recursive even if k>0
            ans.push_back(v);
            }
            return;
        }
        
        for(int i=num;i<=9;i++){
            if(i>n || k<0)
                break; //if target sum becomes greater than the element or size becomes -ve, break the loop
        
            
            v.push_back(i); //take
            k--; //decrement k by 1 so as to keep a check of the remaining no. of elements to be considered
            subsets(i+1,k,n-i,v,ans); 
            v.pop_back();
            k++; //increment k by 1 when the element is not considered
            
            
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        
        subsets(1,k,n,v,ans);
        return ans;
        
    }
};