class Solution {
public:
    
    int n1, n2, n3;
    bool check(int i, int j, string s1, string s2, string s3, vector<vector<int>>& dp){
        
        //if both the indices simultaneously get out of limit, return true since the strings have been interleaved properly
        if(i==n1 && j==n2 && i+j==n3){
            return 1;
        }
        
        //if either of the indices have not yet reached their limit and (i+j) in s3 has reached the string limit , then there is not possibility that it coulb be interleaved
        if(i+j>=n3){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int res= 0;
        if(s1[i]==s3[i+j]){
            res=check(i+1,j,s1,s2,s3,dp);
        }
        
        if(res==true){
            return dp[i][j]=res;
        }
        
        if(s2[j]==s3[i+j]){
            res=check(i,j+1,s1,s2,s3,dp);
        }
        
        return dp[i][j]=res;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(101,vector<int>(101,-1));
        
         n1=s1.length();
         n2=s2.length();
         n3=s3.length();
        
        return check(0,0,s1,s2,s3,dp)==0 ? false: true;
    }
};