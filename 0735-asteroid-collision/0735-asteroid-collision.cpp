class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; //to stoe the surviving asteroids

        for(int i=0;i<asteroids.size();i++){
            if(st.empty() || asteroids[i]>0){
                st.push(asteroids[i]); //take the element if either the stack is empty or if the element is moving in positive direction
            }
            else { //else consider the opposite direction
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])){
                    //if the steroid moving in right direc is smaller than the one moving in left then it will explode so remove all the elements which cannot survive
                    st.pop();
                }
                if(!st.empty() and st.top()==abs(asteroids[i])) {
                    st.pop(); //even if the directions are oppositebut if they are of the same size, remove the elemnt fro the stack considering it to get exploded
                }
                
                else if (st.empty() || st.top()<0){
                    st.push(asteroids[i]); //if the stack becomes empty or since this case for -ve elemnts hence we can simple consider them to survive and add them to the stack
                }
            }
        }
        
        //at last , just reversely store the elements since we are using stack
        
        vector<int> ans(st.size());
        for(int i=st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};