class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1; //only one way possible
        dp[1]=1; //again one way possible
        
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]; //since last two indexes will also contribute in determining the number of ways
        }
        
        return dp[n];
    }
};