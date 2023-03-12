class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //simulation approach
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<int> ans;
        int r=0;
        int c=0;
        int s=0;
        int drows[]={0,1,0,-1};
        int dcols[]={1,0,-1,0};
        
        //base case
        if(m==0){
            return ans;
        }
        //// Iterate from 0 to m * n - 1
        for(int i=0;i<m*n;i++){
            ans.push_back(matrix[r][c]);
            visited[r][c]=true;
            
            int newr=r+drows[s];
            int newc=c+dcols[s];
            
            if(newr>=0 && newr<m && newc>=0 && newc<n && !visited[newr][newc]){
                r=newr;
                c=newc;
                //if the cell is unvisited, it keeps moving in the forward direction
            }
            else{
                //upon crossing the limit, it takes clockwise rotation
                s=(s+1)%4;
                r+=drows[s];
                c+=dcols[s];
            }
            
        }
        return ans;
    }
};