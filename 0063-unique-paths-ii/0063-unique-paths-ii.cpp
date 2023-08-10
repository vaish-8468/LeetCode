class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
     if(mat[0][0]==1 ){
        return 0;
    }
       
  
    vector<vector<int>> dp(n,vector<int>(m,0));
    //one way possible to reach (0,0) from (0,0)

    //we'll count the all possible ways 
    //bottom-up approach
    // from (0,0) to (m-1,n-1)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[0][0]=1;    //one way possible to reach (0,0) from (0,0)
            }
            else{
            int upwards=0;
            int leftwards=0;
            if(mat[i][j]==0){
                if(i>0)
                upwards=dp[i-1][j];

                if(j>0)
                leftwards=dp[i][j-1];

             
               }   
               dp[i][j]=(upwards+leftwards); //numbers of paths from left direction and from upward direction to (i,j)
            }
            
        }
    }
    return (dp[n-1][m-1]);
    }
};