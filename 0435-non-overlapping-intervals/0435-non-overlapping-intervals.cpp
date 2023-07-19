class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](auto const& a, auto const& b){return a[1]<b[1];});
        
        int count=-1;
        vector<int> prev=intervals[0];
        for(int i=0;i<intervals.size();i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            if(prev[1]>intervals[i][0]){
                count++;
            
            }
            else{
                prev=intervals[i];
            }
        }
        return count;
    }
};