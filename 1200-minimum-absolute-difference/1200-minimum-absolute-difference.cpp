class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> v;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int min_=INT_MAX;
        for(int i=0;i<n-1;i++){
            min_=min(min_,(arr[i+1]-arr[i]));
        }
        for(int i=0;i<n-1;i++){
            
            if((arr[i+1]-arr[i])==min_){
                v.push_back({arr[i],arr[i+1]});
            }
        }
        return v;
    }
};