class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> d={{0,5},{1},{2,3,4}};
        vector<pair<int,int>> mp;
        vector<vector<int>> ans;
        for(int i=0;i<groupSizes.size();i++){
            mp.push_back(make_pair(i,groupSizes[i]));
            
        }
        
        sort(mp.begin(),mp.end(),[&](const pair<int,int>& a, const pair<int,int>& b){
            return a.second<b.second;
        });
        
        for(int i=0;i<groupSizes.size();){
            int n=mp[i].second;
            vector<int> group(n);
            int j=0;
            while(n>0){
                group[j]=mp[i].first;
                n--;
                i++;
                j++;
            }
            ans.push_back(group);
        }
        
        return ans;
    }
};