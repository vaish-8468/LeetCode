class Solution {
public:
    int helper(stack<int> st, int num){
        int maxi=-1;
        
        while(!st.empty() && st.top()!=num){
            if(st.top()>num){
                maxi=st.top();
            }
            st.pop();
        }
        return maxi;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      stack<int> st;
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            ans.push_back(helper(st,nums1[i]));
        }
        
        return ans;
    }
        
        
};