class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        //bottom up approach
        //from (n-1) to (0) since (0,0) is fixed
        
        //store the last row as it is
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<triangle[n-1].size();i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
    
            for(int j=i;j>=0;j--){
                //since we need to calc the possiblilies starting from index i only
                int first=triangle[i][j]+dp[i+1][j];
                int second=triangle[i][j]+dp[i+1][j+1];
                
                dp[i][j]=min(first,second);
            }
        }
        return dp[0][0];
    }
};