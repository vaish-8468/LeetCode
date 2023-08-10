class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
          int n=matrix.size();
        //bottom up approach
        //from (n-1) to (0) 
        
        //store the last row as it is
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
    
            for(int j=n-1;j>=0;j--){
                int left=INT_MAX;
                int right=INT_MAX;
                //since we need to calc the possiblilies starting from index i only
                int below=matrix[i][j]+dp[i+1][j];
                if(j>0)
                left=matrix[i][j]+dp[i+1][j-1];
                if(j<n-1)
                right=matrix[i][j]+dp[i+1][j+1];
                
                dp[i][j]=min(below,min(left,right));
            }
        }
        int ans=*min_element(dp[0].begin(),dp[0].end());
        return ans;
    }
};