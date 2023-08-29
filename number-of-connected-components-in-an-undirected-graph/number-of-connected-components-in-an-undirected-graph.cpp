class Solution {
public:
    void dfs(int node, vector<vector<int>>& edges,unordered_map<int,vector<int>>& mp, vector<int>& visited){
        visited[node]=1;
        
        for(auto x: mp[node]){
            if(visited[x]==0){
                dfs(x,edges,mp,visited);
         
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        if(edges.size()==0){
            if(n==0){
                return 0;
            }
            else{
                return n;
            }
        }
        unordered_map<int,vector<int>> mp;
        vector<int> visited(n,0); 
        
        //create adjacency list
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(i,edges,mp,visited);
                count++;
            }
        }
        
        return count;
        
    }
};