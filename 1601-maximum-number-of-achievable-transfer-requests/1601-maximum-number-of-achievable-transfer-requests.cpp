class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        int len = requests.size();
        int total = pow(2,len);
        int maxi = 0;
        vector<int> res;
        for(int i =0;i<=total;i++){
            vector<int> req;
            for(int j = 0;j<len;j++){
                if((i>>j)&1) req.push_back(j);
            }
            vector<int> degree(n,0);
            for(auto j:req){
                degree[requests[j][0]]++;
                degree[requests[j][1]]--;
            }
            for(auto j:degree) {
                if(j!=0) {
                    req.clear();
                    break;
                }
            }
            maxi = max(maxi,(int)req.size());
        }
        return maxi;
//         vector<set<int>> adj(n);
//         vector<vector<int>> degree(n,vector<int>(3,0)); //first elements represents outdegree and second element represents in degree and the third element represents self loop
        
//         for(int i=0;i<requests.size();i++){
//             int u=requests[i][0];
//             int v=requests[i][1];
            
//             if(u==v){
//                 degree[u][2]+=1;
//                 continue;
//             }
//             else{
//             degree[u][0]+=1;
//             degree[v][1]+=1;
            
//             }
//             adj[u].insert(v);
//             adj[v].insert(u);
         
            
//         }
// //         for(int i=0;i<n;i++){
// //             cout<<i<<"=";
// //             for(auto j :adj[i]){
// //                 cout<<j;
// //             }
// //             cout<<endl;
// //         }
    
//         for(int i=0;i<n;i++){
//             if(degree[i][1]==0){
//                 for(auto j : adj[i]){
//                     degree[j][1]-=1;
//                     cout<<j<<" "<<degree[j][1]<<endl;
                    
//                 }
//             }
//         }
//         int ans=0;
        
//         for(int i=0;i<n;i++){
//             if(degree[i][0]-degree[i][1]==0){
//                 ans+=degree[i][0];
//             }
//             else if(degree[i][0]>0 && degree[i][1]>0){
//                 ans+=min(degree[i][0],degree[i][1]);
//             }
//             ans+=degree[i][2];
//             cout<<degree[i][0]<<" "<<degree[i][1]<<endl;
//         }
        
//         return ans;
    }
};