class Solution {
public:
 static bool comp (vector<int> p1, vector<int> p2) {
    return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        stack<vector<int>> st;
        sort(intervals.begin(),intervals.end(),comp);
        st.push(intervals[0]);
        for(int i=0;i<intervals.size();i++){
            vector<int> top=st.top();
            if(top[1]<intervals[i][0]){
                st.push(intervals[i]);
            }
            else if(top[1]<intervals[i][1]){
                top[1]=intervals[i][1];
                st.pop();
                st.push(top);
                
            }
        }
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        return v;
        
        
    }
};