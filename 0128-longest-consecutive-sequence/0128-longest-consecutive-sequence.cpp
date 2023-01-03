class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //unordered set can be used for every band's head lookup
        unordered_set<int> st;
        for(int x:nums){
            st.insert(x);
        }
        int count=0;
        int longest=0;
        
        //iterate over the set
        for(auto x:st){
            int parent_ele=x-1;
            if(st.find(parent_ele)==st.end()){
                int next_ele=x+1;
                count=1;
                while(st.find(next_ele)!=st.end()){
                    count++;
                    next_ele++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};