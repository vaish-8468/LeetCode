class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int> ,int> mp;
        int n=grid.size();
        int count=0;
        for(int i=0;i<n;i++){ //for storing the rows and their frequency of occurence
            if(mp.find(grid[i])==mp.end()){
                mp[grid[i]]=1;
            }
            else{
                mp[grid[i]]++;
            }
        }
        vector<int> col;
        for(int i=0;i<n;i++){
            int j=0;
            while(j<n){
                col.push_back(grid[j][i]);  //to create a vector of column  
                              j++;
            }
            if(mp.find(col)!=mp.end()){
                count+=mp[col];   //if the row and the column matches, their frequency is recorded
            }
            col.clear();  //column is cleared for the refill
                             
        }
        
        return count;
    }
};