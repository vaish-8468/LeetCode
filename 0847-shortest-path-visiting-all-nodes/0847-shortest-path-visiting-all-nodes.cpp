class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1 || n==0){
            return 0;
        }
        set<pair<int,int>> visited; //to store the nodes visited along with their masking
        
        //we'll do simple BFS traversal of nodes
        
        
      
        
        
        queue<pair<int,int>> que;
        
        for(int i=0;i<n;i++){
            que.push(make_pair(i,1<<i));
            
            visited.insert(make_pair(i,1<<i));
        }
        
        int count=0;
        int visited_mask= (1<<n)-1;
        while(!que.empty()){
            
            int N=que.size();
            count++;
            
            while(N--){
            auto ele=que.front();
            que.pop();
            
            int node=ele.first;
            int temp_mask=ele.second;
            
      
            
            for(auto x: graph[node]){
                int curr_mask=temp_mask | (1<<x);
                if(visited_mask==curr_mask){
                return count;
            }
                if(visited.find((make_pair(x,curr_mask)))==visited.end()){
                    que.push(make_pair(x,curr_mask));
                    visited.insert(make_pair(x,curr_mask));
                }
            }
            }
        }
        return -1;
    }
};