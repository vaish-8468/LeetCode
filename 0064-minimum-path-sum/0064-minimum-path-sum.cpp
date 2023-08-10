class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        if(n==1 && m==1){
            return grid[0][0];
        }
        
        vector<vector<int>> dp(n,vector<int>(m,0)); //stores the min sum for path from (0,0) to (i,j)
          dp[0][0]=grid[0][0];
        //the first path will store the actual sum
        
        //store all the min sum acquired for reaching the cell in first column from (0,0) since only forward movement is allowed
        for(int i=1;i<n;i++){
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }
        
        //similarily store all the min sum along the first row
        for(int i=1;i<m;i++){
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
      
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                // if((i==0 && j==0) || i==0 || j==0){
                //     dp[i][j]=grid[i][j];
                // }
                // else {
                    int upward=grid[i][j]+dp[i-1][j];
                    int leftward=grid[i][j]+dp[i][j-1];
                    
                    dp[i][j]=min(upward,leftward);
                // }
            }
        }
        
        return dp[n-1][m-1];
    }
};