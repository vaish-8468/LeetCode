class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ways(m,vector<int>(n,1));
        int i,j;
        for( i=1;i<m;i++){
            for(j=1;j<n;j++){
                
                ways[i][j]=ways[i-1][j]+ways[i][j-1];
            }
        }
        return ways[m-1][n-1];
    }
};
 