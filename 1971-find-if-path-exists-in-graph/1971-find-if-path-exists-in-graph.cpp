class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.size()==0 && source==destination){
            return true;
        }
        
        unordered_map<int, vector<int>> adjList(n);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            //bidirectional or undirected graph
        }
        
        vector<int> visited(n,0);
        queue<int> que;
        que.push(source);
        
        while(!que.empty()){
            int curr=que.front();
            que.pop();
            
            for(auto node: adjList[curr]){
                if(!visited[node]){
                    if(node==destination){
                        return true;
                    }
                    visited[node]=1;
                    que.push(node);
                    
                }
            }
        }
        
        return false;
        
    }
};