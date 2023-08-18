class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //one coplete transaction is considered when buy and sell both are done
        
        
        //Base Case
        //for all possibilities when index is n, profit made will be 0
        
        for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=2;cap++){
                dp[n][buy][cap]=0;
            }
        }
        
        //Base Case
        //for all possibilities when capacity of transaction is already exhausted, profit counted will be 0
        
        for(int ind=0;ind<=n;ind++){
            for(int buy=0;buy<=1;buy++){
                dp[ind][buy][0]=0;
            }
        }
        
      
        //bottom up approach
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int capacity=1;capacity<=2;capacity++){
                int profit=0;
                if(buy){
                    profit=max(-prices[ind]+dp[ind+1][0][capacity], 0+ dp[ind+1][1][capacity]);
                }
                else{
                    //sell and count the trasactions made
                    profit=max(prices[ind]+dp[ind+1][1][capacity-1], 0+dp[ind+1][0][capacity]);
                }
                
                dp[ind][buy][capacity]=profit;
                }
            }
        }
        
        return dp[0][1][2];
    }
};