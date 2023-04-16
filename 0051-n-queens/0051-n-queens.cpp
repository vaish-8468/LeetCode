#include<bits/stdc++.h>
class Solution {
public:
    void find(int col, vector<string>& v, vector<vector<string>>& ans, vector<bool>& top_left, vector<bool>& left, vector<bool>& bottom_left,int n){
        if(col==n){
            ans.push_back(v);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(top_left[n-1+col-row]==false && left[row]==false && bottom_left[row+col]==false){
                v[row][col]='Q';
                top_left[n-1+col-row]=true;
                left[row]=true;
                bottom_left[row+col]=true;
                find(col+1,v,ans,top_left,left,bottom_left,n);
                v[row][col]='.';
                top_left[n-1+col-row]=false;
                left[row]=false;
                bottom_left[row+col]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string ss(n,'.');
        vector<string> v(n,ss);
        // for(int i=0;i<n;i++){
        //     v[i]=ss;
        // }
        vector<bool> top_left(2*n-1,false), left(n,false),bottom_left(2*n-1,false);
        find(0,v,ans,top_left,left,bottom_left,n);
        return ans;
    }
};