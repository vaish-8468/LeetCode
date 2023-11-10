class Solution {
public:
    
    //TC=O(N);
    //SC=O(N);
    void dfs(int node, vector<int>& ans, unordered_map<int, vector<int>>& mp, int prev ){
        ans.push_back(node);
        //add node into the resultant
        
        for(auto x: mp[node]){
            if(x!=prev){
                //pass the curr node as the prev node and keep traversing
                dfs(x,ans,mp,node);
                //instead of visited vector, keep a record of the previous node
                //since the adjacency list has been made such that the nodes are adjacent to each other
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
     
        
        unordered_map<int,vector<int>> mp;
        vector<int> ans;
        
        //make adjacency list
        for(int i=0;i<adjacentPairs.size();i++){
            int u=adjacentPairs[i][0];
            int v=adjacentPairs[i][1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
            
        }
        int start=-1;//initially garbage point
        
        //now start dfs/bfs raversal from the node with degree 1
        //since it will have only one adjacent node to deal with
        for(auto x:mp){
            if(x.second.size()==1){
                start=x.first;
                break;
            }
        }
        
        
        dfs(start,ans,mp,INT_MIN);
        
        
        return ans;
    }
};