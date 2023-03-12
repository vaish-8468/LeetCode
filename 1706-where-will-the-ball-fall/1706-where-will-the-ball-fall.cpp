class Solution {
public:
    
   
    int check(vector<vector<int>>& grid,vector<vector<int>>& visited, int m, int n){
        if(m==grid.size()){
            return n;
        }
        if(m>=0 && m<grid.size() && n>=0 && n<grid[0].size()){
            if(grid[m][n]==1 && m>=0 && m<grid.size() && n+1>=0 && n+1<grid[0].size() && grid[m][n+1]==1){
                 if(visited[m+1][n+1]!=0){
            return visited[m+1][n+1];
        }
                else{
                    return visited[m+1][n+1]=check(grid,visited,m+1,n+1);
                }
                
            }
        
            else if(grid[m][n]==-1 && m>=0 && m<grid.size() && n-1>=0 && n-1<grid[0].size() && grid[m][n-1]==-1){
                 if(visited[m+1][n-1]!=0){
            return visited[m+1][n-1];
        }
                else{
                    return visited[m+1][n-1]=check(grid,visited,m+1,n-1);
                }
                
            }
       
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int s=grid.size();
        int t=grid[0].size();
        vector<int> ans;
        vector<vector<int>> visited(101, vector<int>(101,0));
        for(int i=0;i<t;i++){
            ans.push_back(check(grid,visited,0,i));
        }
        return ans;
    }
};