class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        int n=matrix[0].size();
        
        set<int> num;
        
        for(int i=0;i<m;i++){
            int min_row=matrix[i][0];
            for(int j=0;j<n;j++){
                min_row=min(min_row,matrix[i][j]);
            }
            num.insert(min_row);
        }
        
        for(int i=0;i<n;i++){
            int maxi_col=matrix[0][i];
            for(int j=0;j<m;j++){
                maxi_col=max(maxi_col,matrix[j][i]);
            }
            if(num.count(maxi_col)!=0){
                ans.push_back(maxi_col);
        }
        }
            return ans;
        
    }
};