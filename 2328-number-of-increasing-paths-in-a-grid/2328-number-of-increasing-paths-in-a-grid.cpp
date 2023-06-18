class Solution {
public:
    int mod=1e9+7;
    
    bool isValid(int x,int y, vector<vector<int>>& grid){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()){
            return false;
        }
        return true;
    }
    
    
    int dfs(int i,int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(dp[i][j]!=-1){ //the ans for the cell has already been calculated
            return dp[i][j];
        }
        int ans=1; //for each cell, one path is counted for itself i.e self path
        int drows[4]={1,0,0,-1};
        int dcols[4]={0,-1,1,0};
        
        for(int l=0;l<4;l++){
            int newr=i+drows[l];
            int newc=j+dcols[l]; //since moverment to all four directions is allowed
            if(isValid(newr,newc,grid) && grid[i][j]>grid[newr][newc]){ //if the cell index does not lies out of range and the second condition is for the strictly increasing path
                //we'll be counting the ans while backtracking as we;ll keep adding the ans of the last cell to the current cell and add 1 for its own self path
                ans=(ans%mod + dfs(newr,newc,grid,dp)%mod)%mod;
            }
        }
        return dp[i][j]=ans%mod; //stores the ans in the dp
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1)); //dp is initialized as -1 for total number of paths for each cell
        int m=grid.size();
        int n=grid[0].size();
        int count=0; //for storing the total number of increasing paths
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                count=(count%mod+dfs(i,j,grid,dp)%mod)%mod; //dfs is used for traversal and dp is used for memoization of count for each cell
            }
        }
        return (int)count%mod;
        
    }
};