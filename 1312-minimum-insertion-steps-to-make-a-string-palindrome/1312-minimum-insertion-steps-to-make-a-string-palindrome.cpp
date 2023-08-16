class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        
        //find the longest palindromic subsequence length 
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s[n-j]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // to make the whole string palindromic we have  to insert the non-palindromic elemnts
        //the min number of operations reuquired will be the count of those elements
        
        //max number will be the length of the original string since whole string can be copied in reverse manner and concatenated with the original string
        int minSteps=n-dp[n][n];
        
        return minSteps;
    }
};