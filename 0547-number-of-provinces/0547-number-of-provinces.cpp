class Solution {
public:
    
    void dfs(int node, vector<vector<int>> &isConnected, vector<int> &visited){
        visited[node]=1;
        
        for(int i=0; i<isConnected[node].size();i++){
            if(isConnected[node][i]==1 && node!=i){
                if(visited[i]==0){
                dfs(i,isConnected,visited);
                    }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(),0);
        int ans=0;
        
        for(int i=0;i<isConnected.size();i++){
            if(visited[i]==0){
                dfs(i,isConnected,visited);
                ans++;
            }
        }
        return ans;
    }
};