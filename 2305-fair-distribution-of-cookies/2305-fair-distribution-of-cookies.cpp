class Solution {
public:
    int result=INT_MAX;
    void checkFairness(int index, vector<int>& cookies, vector<int>& distributions, int k){
        
        if(index==cookies.size()){ //backtracking
            int unfairness=*max_element(distributions.begin(),distributions.end()); //calculate the max sum when all the elements of cookies are considered
            result=min(result,unfairness); //update if it is less than the previous calculated maximum
            return;
        }
        
        int cookie=cookies[index]; //cookie to be distributed
        
        for(int i=0;i<k;i++){ //branching
            distributions[i]+=cookie;  //consider for the ith child
            checkFairness(index+1,cookies,distributions,k); //move onto the next cookie
            distributions[i]-=cookie;  //do not consider for ith child
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distributions(k,0); //it will be of size k as we want to distribute it among k members
        
        checkFairness(0,cookies,distributions,k);
        
        return result;
    }
};