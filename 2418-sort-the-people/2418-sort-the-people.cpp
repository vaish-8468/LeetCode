#include<bits/stdc++.h>
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // sort(names.begin(),names.end(),[&](const vector<int>::iterator& a, const vector<int>::iterator& b){
        //     return heights.begin()+a>heights.end()+b;
        // }))
        
        //TC: O(nlogn)
        //SC: O(n)
        vector<pair<int,string>> vec;
        vector<string> ans;
        
        for(int i=0;i<names.size();i++){
            vec.push_back({heights[i],names[i]});
        }
        sort(vec.begin(),vec.end(),[&](const pair<int,string>& a, const pair<int,string>& b){
            return a.first>b.first;
        });
        
        for(auto v : vec){
            ans.push_back(v.second);
        }
            
            return ans;
        /*
        //TC: O(nlogn)
        //SC: O(n)
        vector<int> indices(heights.size());
        iota(indices.begin(), indices.end(), 0); //stores values in increasing order starting from 0
        sort(indices.begin(), indices.end(), [&](int i, int j) { return heights[i] > heights[j]; });
        vector<string> sortedNames(indices.size());
        transform(indices.begin(), indices.end(), sortedNames.begin(), [&](int i) { return names[i]; });
        return sortedNames;
        */
        
    
    }
};