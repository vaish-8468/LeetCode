//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    bool isvalid(int node,int color, int colour[], bool graph[101][101],int n){
        for(int i=0;i<n;i++){
            if(i!=node && graph[i][node]==1 && colour[i]==color){
                return false;
            }
        }
            return true;
        
    }
    
    bool check(int node, int colour[], int m, int n, bool graph[101][101]){
        if(node==n){
            return true;
        }
        for(int i=1;i<=m;i++){
            if(isvalid(node,i,colour,graph,n)){
                colour[node]=i;
                if(check(node+1,colour,m,n,graph)){
                    return true;
                }
                colour[node]=0;
            }
        }
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        int colour[n]={0};
        if(check(0,colour,m,n,graph)){
            return true;
        }
        else{
            return false;
        }
        
        // your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends