class Solution {
public:
    int dp[51][51][51];
    vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}};
    int mod=1e9+7;
    
    
    int helperFunc(int startRow, int startCol, int maxMoves, int m, int n){
        if(startRow<0 || startRow>=m || startCol<0 || startCol>=n){
            return 1;
        }
        if(maxMoves<=0){
            //all moves exhauted
            return 0;
        }
        
        if(dp[startRow][startCol][maxMoves]!=-1){
            return dp[startRow][startCol][maxMoves];
        }
        
        int ans=0;
        for(vector<int>& dir: direction){
            int newR=startRow+dir[0];
            int newC=startCol+dir[1];
            
            ans=(ans+helperFunc(newR,newC,maxMoves-1,m,n))%mod;
        }
        
        return dp[startRow][startCol][maxMoves]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        
        return helperFunc(startRow,startColumn,maxMove,m,n);
    }
};