class Solution {
public:
    //https://www.youtube.com/watch?v=k8LBJqGLLQE
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<vector<int>> adj(n); //to form new graph with reversed directed edges
        
        queue<int> que; //queu to store all the nodes which are not a part of the cycle
        vector<int> indegree(n,0); //to store indegree for every node
        vector<bool> isSafe(n,false); //to keep a record of the nodes who are not a part of the cycle
        vector<int> ans;
        
        for(int u=0;u<n;u++){
            for(auto& v: graph[u]){
                adj[v].push_back(u); //makes an edge
                indegree[u]++; //increments indegree of u
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                que.push(i); //pushes al the nodes in the queue with indegree 0 as per the kahn's algo of topological sort
            }
        }
        
        while(!que.empty()){
            int curr=que.front();
            que.pop();
            
            isSafe[curr]=true; //marks the node as true
            
            for(auto& v: adj[curr]){
                indegree[v]--;
                 if(indegree[v]==0){
                que.push(v); //if indegree is 0, push the node as per the kahn's algo
            }//decrements indegree of all the adjacent nodes of curr
        }
          
            
    }
        
        for(int i=0;i<n;i++){
            if(isSafe[i]==true)
            ans.push_back(i); //all the nodes that have been popped from the queue are safe nodes
        }
        return ans;
    }
};