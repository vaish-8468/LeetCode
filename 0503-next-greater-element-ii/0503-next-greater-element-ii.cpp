class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> ans(n,-1);  //since if it doesn't exists, it should return -1 as an index
        
        for(int i=2*n-1;i>=0;i--){ //i=2*n-1 to basically duplicate the vector and opearte it in circular manner
            
            while(!st.empty() && st.top()<=nums[i%n]){  //% operator will restore index range whenever i>n
                st.pop();  //remove all the lements from the stack which are smaller than num[i%n]
            }
                if(!st.empty() ){
                    ans.at(i%n)=st.top();
                }   //the top element of the stack will always contain the greatest element of all elements in the stack
            else{
                ans[i%n]=-1;  //store the index -1 if there no element greater than nums[i%n] i.e stack is empty
            }
            
            st.push(nums[i%n]);   //keep filling the stack for every operation  
        }
        return ans;
    }
};