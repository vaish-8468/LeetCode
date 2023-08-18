class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        //form the adjacency list and count the number of adjacent nodes to the city to count the number of roads directly connected with the city
        
        int maxi=0;
        unordered_map<int,unordered_set<int>> adj;
        
        for(auto& road: roads){
            int u=road[0];
            int v=road[1];
            
            adj[u].insert(v);
            adj[v].insert(u);
        }
        
        //find the max sum of any two connected nodes
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int firstCity=adj[i].size();
                int secondCity=adj[j].size();
                
                int totalConnections=firstCity+secondCity;
                
                if(adj[i].find(j)!=adj[i].end()){
                    totalConnections-=1;
                    //since the roads have been conted twice
                }
                
                maxi=max(maxi,totalConnections);
            }
        }
        
        return maxi;
        
    }
};