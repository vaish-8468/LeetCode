class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        res.push_back({1});
        res.push_back({1,1}); //base cases
        if(rowIndex==0 || rowIndex==1){
            return res[rowIndex];
        }
        
       
        int i=2;
        while(i<=rowIndex){
           vector<int> ans(i+1,1); 
            for(int j=1;j<i;j++){
               ans[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(ans);
            i++;
        }
        
        return res[rowIndex];
    }
};