//define a class for union implementation
class UnionSet{
    private:
    vector<int> root;
    
    public: 
    UnionSet(int size){
        for(int i=0;i<size;i++){
            //initialize root of every node being itself
            root.push_back(i);
            
        }
    }
    
    int find(int x){
        //O(n)
        //Quick Union Implementation
        //we are storing the immediate parent node of every vertex
        while(root[x]!=x){
            x=root[x];
        }
        return x;
    }
    
     void Union(int x, int y){
        int rootX=find(x); //O(n)
        int rootY=find(y); //O(n)
        
        if(rootX!=rootY){ //if the components are disconnected, connect them
            root[rootY]=rootX;
        }
    }
    
    bool connected(int x, int y){
        return find(x)==find(y);
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        //the idea to solve this question is to create union of components and record the last time when all get connected into a single component
        
        
        //sort the edges according to increasing order of timestamp 
        sort(logs.begin(),logs.end(),[&](const vector<int>& a, const vector<int>& b){
            return a[0]<b[0];
        });
        
        UnionSet set_(n);
        //corner case
        //for keeping a record of the connected components, we can initialize edge variable with n-1 since for a connected graph with n nodes , it contains n-1 edges, hence if all the edges have been utilized that means all the nodes have been connected
        int edges=n-1;
        int ans=-1;
        for(int i=0;i<logs.size();i++){
            int u=logs[i][1];
            int v=logs[i][2];
            
            if(!set_.connected(u,v)){
                set_.Union(u,v);
                //update ans only when two new components are united
                ans=logs[i][0];
                edges--;
            }
        }
        return edges==0?ans:-1;
    }
};