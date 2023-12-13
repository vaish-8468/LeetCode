class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
        
        vector<int> rowC(m,0), colC(n,0);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(mat[i][j]==1){
                   rowC[i]++; //increment row count
                   colC[j]++; //increment column count
               } 
            }
        }
        
        int ans=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && colC[j]==1 && rowC[i]==1){ 
                    //if the cell contains 1
                    //rowC[i]==1 and colC[j]==1 signifies that their no other 1
                    //in this whole row and column
                    ans++;
                }
            }
        }
        return ans;
    }
};