class Solution {
public:
    
    // void combination(int index, vector<int>& candidates, vector<int>& v, vector<vector<int>>& ans, int target){
        
//         if(index==candidates.size()){
//             if(target==0){
//                 ans.push_back(v);
//                 // v.clear();
//             }
//             else{
//                 return;
//             }
//         }
//         if(candidates[index]<=target){
//             //take
//         v.push_back(candidates[index]);
//         combination(index,candidates,v,ans,target-candidates[index]);
//             //do-not take
//         v.pop_back();
//         }
//         combination(index+1,candidates,v,ans,target);
        
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         int n=candidates.size();
//         vector<int> v;
//         vector<vector<int>> ans;
        
//         combination(0,candidates,v,ans,target);
//         return ans;
        
//     }
    vector<vector<int>>ans;
    void help(int i,int t,vector<int>&c,vector<int>&vec){
        if(t==0){
            ans.push_back(vec);
            return;
        }
        if(t<0){
            return;
        }
        if(i==c.size()){
            return;
        }
        help(i+1,t,c,vec); // if ith ele is ignored
        vec.push_back(c[i]);
        help(i,t-c[i],c,vec);// if ith ele is not ignored
        vec.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int>vec;
        help(0,t,c,vec);
        return ans;
    }
};