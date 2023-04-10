class Solution {
public:
    
    void combination(int index, vector<int>& candidates, vector<int>& v, vector<vector<int>>& ans, int target){
        
        if(target==0){
            ans.push_back(v);
        return;
        }
        if(index==candidates.size()){
          return;
        }
        if(target<0){
            return ;
        }
        v.push_back(candidates[index]); //take
        combination(index,candidates,v,ans,target-candidates[index]);
        v.pop_back(); //do-not take
        combination(index+1,candidates,v,ans,target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> v;
        vector<vector<int>>ans;
        combination(0,candidates,v,ans,target);
        return ans;
    }
};