//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

#include<bits/stdc++.h>


class Solution{
    public:
    
    void find(int x, int y, int n, vector<vector<int>> &m, vector<string> &ans, string s,vector<vector<int>> &visited){
        if(x==n-1 && y==n-1){
            ans.push_back(s);
            return;
        }
        //writing functions in lexicographical order
        
        
        //for downward movement
        if(x+1<n &&  visited[x+1][y]!=1 && m[x+1][y]==1){
            visited[x][y]=1;
            find(x+1,y,n,m,ans,s+'D',visited);
            visited[x][y]=0; //backtrack
        }
        
        //for leftward movement
        if( y-1>=0 && visited[x][y-1]!=1 && m[x][y-1]==1){
            visited[x][y]=1;
            find(x,y-1,n,m,ans,s+'L',visited);
            visited[x][y]=0; //backtrack
        }
        
        
        //for rightward movement
        if( y+1<n && visited[x][y+1]!=1 && m[x][y+1]==1){
            visited[x][y]=1;
            find(x,y+1,n,m,ans,s+'R',visited);
            visited[x][y]=0; //backtrack
        }
        
        
        
        //for upward movement
        if(x-1>=0  && visited[x-1][y]!=1 && m[x-1][y]==1){
            visited[x][y]=1;
            find(x-1,y,n,m,ans,s+'U',visited);
            visited[x][y]=0; //backtrack
        }
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n,vector<int>(n,0));
        string s="";
        if(m[0][0]==1){
        find(0,0,n,m,ans,s,visited);
        }
        
        return ans;
        // Your code goes here
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends