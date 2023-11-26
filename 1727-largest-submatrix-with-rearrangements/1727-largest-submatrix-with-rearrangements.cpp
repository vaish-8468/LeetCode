class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]!=0 && i>0){
                    matrix[i][j]+=matrix[i-1][j]; //keep a record of the height of the column, if it is zero, then don't count the cell's contribution and reset the height to 0
                }
            }
            
            vector<int> row=matrix[i]; //for each row, sort it in decreasing order
            sort(row.begin(),row.end(),greater());
            
            //assuming that each cell to the left of the current cell would be of height greater than the current cell, hence, we'll find the area of the cell and update the answer
            for(int k=0;k<row.size();k++){
                ans=max(ans,row[k]*(k+1));
            }
        }
        
        return ans;
    }
};