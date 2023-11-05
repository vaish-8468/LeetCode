class Solution {
public:
    
    void solve(int idx, string& s, vector<string>& ans,int n, int countLeft, int countRight){
        if(idx==2*n){
            if(countLeft==0 && countRight==0){
            ans.push_back(s);
            }
            return;
        }
        
        if(countLeft>0){
        //choose opening bracket
        s+='(';
        solve(idx+1,s,ans,n,countLeft-1,countRight);
        //backtrack
        s.pop_back();
        }
        
        if(countRight>countLeft){
        //choose closing bracket
        s+=')';
        solve(idx+1,s,ans,n,countLeft,countRight-1);
        //backtrack
        s.pop_back();
        
        }
        
    }
    vector<string> generateParenthesis(int n) {
        if(n==1){
            return {"()"};
        }
      
        vector<string> ans;
        string s;
        int countLeft=n;
        int countRight=n;
        
        solve(0,s,ans,n,countLeft,countRight);
        
        // for(auto x:ans){
        //     res.push_back(x);
        // }
        return ans;
    }
};