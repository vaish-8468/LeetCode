class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size(); //row
        int n=mat[0].size(); //column
        
        
        vector<int> ans;
        vector<int> visited(m,-1);
        //we are traversing the matrix column wise
        //once all the k rows are acquired, loop will end
        
        for(int i=0; i<n;i++){
            if(ans.size()==k){
                break;
            }
            for(int j=0;j<m;j++){
                if(ans.size()==k){
                break;
            }
             //initially, we'll prefer all those indices which have civilians first   
                if(mat[j][i]==0 && visited[j]==-1){
                    ans.push_back(j);
                    visited[j]=1;
                }
            }
        }
        
        int i=0;
        //if we still want more number of rows, we'll check from the left ones
        while(ans.size()!=k){
            if(visited[i]==-1){
                ans.push_back(i);
            }
            i++;
        }
        
        return ans;
    }
};