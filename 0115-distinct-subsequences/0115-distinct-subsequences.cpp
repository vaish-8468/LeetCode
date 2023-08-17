class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        
        
        for(int i=0;i<=n;i++){
            dp[i][0]=1; //when all the elements of string 2 are traversed
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j]; //take and not take
                }
                else{
                    dp[i][j]=dp[i-1][j]; //not take when it is not equal
                }
            }
        }
        
        return (int)dp[n][m];
    }
};