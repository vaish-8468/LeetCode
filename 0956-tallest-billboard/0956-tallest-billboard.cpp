class Solution {
public:
    int min_=-1e4;
    int ans;
    int n;
    int dp[21][2*5000+1]; //using dp for memoization to overcome overlapping subproblems and optimize time complexity
        //dp states used are index and difference
    vector<int> rods;
    
    int solve(int index, int difference){
        if(index==n){//if it raeches the end
            if(difference==0){
                return 0; //as the rod values has already been added no need to add henceforth
            }
            return min_; //return anything minimum which won't effect the ans even if the iterator reaches the end
        }
        
        int &ans= dp[index][difference+5000];  //storing the address of dp[index] at ans
        if(ans!=-1){
            return ans; //as max height for that index has already been calculated
        }
        
        int option1=solve(index+1,difference); //do not take
        int option2=rods[index]+solve(index+1,difference+rods[index]); //take it but add in support 1
        int option3=solve(index+1, difference-rods[index]);
        
        return ans=max({option1, option2, option3}); //updating the ans with max height at that index
        
    }
    int tallestBillboard(vector<int>& rods) {
        this->rods=rods;
        n=rods.size();
        
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0);
        
        if(ans<0){
            return 0;
        }
        else return ans;
    }
};