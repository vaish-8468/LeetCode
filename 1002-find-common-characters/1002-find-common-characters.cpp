#include<bits/stdc++.h>
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        if(words.size()==1){
            int l=words[0].size();
            int i=0;
            while(i<l){
                string s;
                ans.push_back(s+words[0][i]);
                i++;
            }
            return ans;
        }
        map<char,vector<int>> mp; //alphabet: {frequency at index}
        int n=words.size();
        
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                if(mp.find(words[i][j])==mp.end()){
                    vector<int> v(n,0);
                    v[i]=1;
                    mp[words[i][j]].assign(v.begin(),v.end());
                    
                }
                else{
                    mp[words[i][j]][i]++;
                }
            }
        }
        
        for(auto x: mp){
            string s;
            vector<int> v=x.second;
            cout<<x.first<<" "<<v[0]<<" ";
            int mini=v[0];
            for(int i=1;i<n;i++){
                cout<<v[i]<<" ";
                if(v[i]<mini){
                    mini=v[i];
                }
            }
                while(mini--){
                    ans.push_back(s+x.first);
                }
            
            cout<<endl;
            
        }
        
        return ans;
    }
};