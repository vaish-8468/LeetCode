class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); //make a graph
        
        vector<int> indegree(numCourses,0); //keep a record of indegree of all nodes/courses
        
        queue<int> que; //implement topological sort and keep a check if all the nodes/courses have been visited or not
        
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][1];  //u->v as given in the ques b->a
            int v=prerequisites[i][0];
            
            adj[u].push_back(v); //store all the adjacent outgoing edge nodes
            indegree[v]++; //count the indegree of v
        }
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){ //push all the nodes in the queue with indegree 0 as per the topoplogical sort
                que.push(i);
            }
        }
        
        while(!que.empty()){
            int curr=que.front();
            que.pop();
            
            for(auto& nextcurr: adj[curr]){
                indegree[nextcurr]--; //keep visiting the nodes and decrementing their indegrees
                if(indegree[nextcurr]==0){ //if node with 0 indegree found, push them in the queue
                    que.push(nextcurr);
                }
            }
        }
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]!=0){ //if any of the node with indegree>0 is found
                return false; //then that means the node is involved in a cycle, hence it can never be finished
            }
        }
        
        return true; //otherwise it can be finishes when all the node's indegree becomes 0
        
    }
};