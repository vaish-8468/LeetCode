class UnionSet{
    private: 
    vector<int> root;
    
    public:
    UnionSet(int size){
        for(int i=0;i<size;i++){
            root.push_back(i);
        }
    }
    
    int find(int node){
        while(root[node]!=node){
            node=root[node];
        }
        return node; //returns the root of the tree
    }
    
    bool Union(int x, int y){
        int rootX=find(x);
        int rootY=find(y);
        
        if(rootX==rootY){
            //cycle found
            return false;
        }
        root[rootX]=rootY;
        return true;
    }
};

class Solution {
public:
    
   
    
    bool validTree(int n, vector<vector<int>>& edges) {
        //a graph is a valid tree if it is connected and contains no cycle in any case
        
        if(n-1!=edges.size()){
            return false;
        }
        
        UnionSet UniSet(n);
        
        //create an adjacency list
 
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            if(!UniSet.Union(u,v)){
                return false;
            }
        }
        
     return true;
    }
};