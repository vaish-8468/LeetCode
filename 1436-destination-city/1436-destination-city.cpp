class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> hasOutgoing;
        for (int i = 0; i < paths.size(); i++) {
            hasOutgoing.insert(paths[i][0]);
        }
        
        for (int i = 0; i < paths.size(); i++) {
            string candidate = paths[i][1];
            if (hasOutgoing.find(candidate) == hasOutgoing.end()) {
                return candidate;
            }
        }
        
        return "";
    }
};




// class Solution {
// public:
//     string destCity(vector<vector<string>>& paths) {
//         unordered_map<string,vector<string>> adj;
//         set<string> st;
//         string ans;
//         for(int i=0;i<paths.size();i++){
//             string u=paths[i][0];
//             string v=paths[i][1];
//             st.insert(u);
//             st.insert(v);
//             adj[u].push_back(v);
//         }
        
//         for(auto x: st){
//             if(adj.find(x)==adj.end()){
//                 ans=x;
//                 break;
//             }
//         }
        
//         return ans;
//     }
// };