//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  void dfs(int node, vector<int> &visited, vector<int> adj[], vector<int> &ans){
      ans.push_back(node); //stores the traversal order
      visited[node]=1;   //marks the node as visited
      for(auto x: adj[node]){  //recursively calls for all neighbours
          if(visited[x]==0){ //if the node is unvisited
              dfs(x,visited,adj,ans);
          }
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);  //vector storing the node visited status
        vector<int> ans;
        dfs(0,visited,adj,ans);
        return ans;
        
        
        /*
                                        0
                                    /    |   \
                                    2    3    1
                                 /    \  |     |
                                 0     4 0      0
                                       \
                                       2
                                       
                                       ans= 0 2 4 3 1
        
        
        */
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends