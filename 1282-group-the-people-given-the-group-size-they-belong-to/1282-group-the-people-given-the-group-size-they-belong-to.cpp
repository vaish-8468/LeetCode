class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int>> mp;
        vector<vector<int>> ans;
        //make pair of indices along with their groupp size
        for(int i=0;i<groupSizes.size();i++){
            mp.push_back(make_pair(i,groupSizes[i]));
            
        }
        
        //sort the vector according to the group sizes
        sort(mp.begin(),mp.end(),[&](const pair<int,int>& a, const pair<int,int>& b){
            return a.second<b.second;
        });
        
        //start grouping the elements as per the group size
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