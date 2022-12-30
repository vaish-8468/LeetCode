class Solution {
public:
    void helper(vector<int> n ,vector<int> l,vector<vector<int>> &ans){
    if(n.size()==0)
    return;
    
    int s=n[n.size()-1];n.pop_back();
    helper(n,l,ans);
    
    
    l.push_back(s);
    helper(n,l,ans);
    ans.push_back(l);
    
}
   

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> l;
    ans.push_back(l);
    helper(nums,l,ans);
    return ans;
}

   
};