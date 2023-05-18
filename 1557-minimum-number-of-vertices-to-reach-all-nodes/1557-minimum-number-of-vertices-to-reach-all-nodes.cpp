#include<bits/stdc++.h>
class Solution {
public:
    
    //to find the minimum no. of vertices to reach all nodes, we need to search for a node which has 0 indegree such that
    //on choosing it to be the starting node, no other nodes should be left untracked
    
    //minimum no. of vertices actually asks to determine number of nodes present with indegree 0
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<n;i++){
        mp[i]=0;
            //initializing the indegree of nodes as 0
        }
        for(int i=0;i<edges.size();i++){
            mp[edges[i][1]]++;
        }
    
        for(auto it : mp){
            if(it.second==0){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};