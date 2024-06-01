class Solution {
public:
    int scoreOfString(string s) {
        int n=s.length();
        
        int ans=0;
        
        for(int i=0;i<n-1;i++){
            ans+=abs((s[i+1]-'a')-(s[i]-'a'));
        }
        
        return ans;
    }
};