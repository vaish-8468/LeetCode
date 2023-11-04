class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // stack<int> st; //no need to define a stack, we can simply assume the stack operations being performed
        vector<string> ans;

        int i=0;//index for target
        int j=1; // curr stream
        //run loop till both stream and target size are available to use
        while(i<target.size() && j<=n){
            // st.push(j);
            //push all the stream elements one by one
            ans.push_back("Push");
            if(target[i]==j){
                i++;
                //target elemenet matched!
                //move to the next element
            }
            else{
                // st.pop();
                ans.push_back("Pop");
                //target elemenet didn't matched!
                //remove the element and move onto the next stream element
            }
            j++;
            
        }
        
        return ans;
        
    }
};