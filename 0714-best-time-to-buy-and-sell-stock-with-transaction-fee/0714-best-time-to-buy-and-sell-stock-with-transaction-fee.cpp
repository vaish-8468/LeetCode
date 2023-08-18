class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        
        //base case
        //for all n, no profit will be counted as the araay has been fully traversed
        
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                
                if(buy){
                    profit=max(-prices[ind]+dp[ind+1][0],      0+dp[ind+1][1]);
                    //           bought    do not buy next    not bought  buy next
                }
                
                else{
                    profit=max(prices[ind]-fee+dp[ind+1][1], 0+dp[ind+1][0]);
                      //        sold and completed one transaction so buy next   otherwise   not sold , then stock on hold , do not buy next
                }
                
                dp[ind][buy]=profit;
            }
        }
        
        return dp[0][1]; //when stock was bought
    }
};