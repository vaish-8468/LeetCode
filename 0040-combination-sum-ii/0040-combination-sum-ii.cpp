class Solution {
public:
    void combination(int index, vector<int>& candidates, vector<int> v, vector<vector<int>> &ans, int target){
        if(target==0){
            ans.push_back(v);
            return;
        }
       for(int i=index;i<candidates.size();i++){
           //loop is being used so as to maintain the order 
           if(i>index && candidates[i]==candidates[i-1]){
               continue;
           }
           //i>index is to ensure that element is not repeated
           if(candidates[i]>target){
               break;
           }
        v.push_back(candidates[i]); //take
        combination(i+1,candidates,v,ans,target-candidates[i]); //i+1 is being done so that no element at a particular index is repeated or considered more than once
        v.pop_back(); //do-not take
       }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //to maintain the order, sort the vector
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<int> v;
        vector<vector<int>> ans;
        combination(0,candidates,v,ans,target);
        return ans;
    }
};