class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++){ //when str1 is fully traversed
            dp[i][0]=i;  //number of operations will to convert an empty str1 into str2 is the len pf the remaining elemnys of str2 
        }
        
        for(int j=0;j<=m;j++){ //when str2 is fully traversed
            dp[0][j]=j;
            //num of min operations to convert str1 into str2 will be the delete all the remaining elements of str1
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1]; //elemnts matched, store the previous state ans
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                                   //delete     insert     replace
                }
            }
        }
     return dp[n][m];
    }
};