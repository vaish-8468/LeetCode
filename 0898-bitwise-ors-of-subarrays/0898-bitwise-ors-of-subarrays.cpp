class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
       
        unordered_set<int> prev,ans;
        for(int i=0;i<arr.size();i++){
            unordered_set<int> res;
            for(auto x: prev){
                res.insert(arr[i]|x);
            }
            res.insert(arr[i]);
            for(auto x: res){
                ans.insert(x);
            }
            prev=res;
        }
        
        return ans.size();
        
        
    }
};