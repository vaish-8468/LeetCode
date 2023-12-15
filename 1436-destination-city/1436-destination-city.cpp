class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,vector<string>> adj;
        set<string> st;
        string ans;
        for(int i=0;i<paths.size();i++){
            string u=paths[i][0];
            string v=paths[i][1];
            st.insert(u);
            st.insert(v);
            adj[u].push_back(v);
        }
        
        for(auto x: st){
            if(adj.find(x)==adj.end()){
                ans=x;
                break;
            }
        }
        
        return ans;
    }
};