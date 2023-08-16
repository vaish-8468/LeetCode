class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        int lenLCS=dp[n][m]; //from LCS concept
        int deletions=n-lenLCS; //min deletions to be performed to achieve LCS from word1
        int insertions=m-lenLCS; //min insertions to be made in LCS to make it word2
        
        return insertions+deletions; //total opeartions;
    }
};