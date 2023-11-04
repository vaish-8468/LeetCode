class Solution {
public:
    void placeQueens(int col, int n, vector<string>& board, set<vector<string>>& ans, vector<bool>&top_left, vector<bool>&left, vector<bool>& bottom_left){
        if(col==n){
            ans.insert(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(bottom_left[row+col]==false && left[row]==false && top_left[n-1+col-row]==false){
                //place
                board[row][col]='Q';
                bottom_left[row+col]=true;
                top_left[n-1+col-row]=true;
                left[row]=true;
                
                placeQueens(col+1,n,board,ans,top_left,left,bottom_left);
                
                //backtrack
                board[row][col]='.';
                bottom_left[row+col]=false;
                top_left[n-1+col-row]=false;
                left[row]=false;
                
            }
        }
    }
    int totalNQueens(int n) {
        //set of vectors have been used here in order to avoid duplicates
        set<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n,s);
        vector<bool> top_left(2*n-1,false), bottom_left(2*n-1,false), left(n,false);
        placeQueens(0,n,board,ans,top_left,left,bottom_left);
        
        return ans.size();
        
    }
};