class Solution {
public:
    
    int calcMaxProfit(int index, int buy,vector<int>& prices, vector<vector<int>>& dp){
        //0->do not buy
        //1->buy
        
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        
        int profit=0;
        if(buy==1){
            profit=max(-prices[index]+calcMaxProfit(index+1,0,prices,dp), 0+calcMaxProfit(index+1,1,prices,dp));
                            //buy              do not buy next       OR    do not buy now          buy later
        }
        else{
            profit=max(prices[index]+calcMaxProfit(index+1,1,prices,dp), 0+ calcMaxProfit(index+1,0,prices,dp));
                           //sold          //buy next                  //not sold            //do not buy as already in stock
        }
        
        return dp[index][buy]=profit;
        
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        
        return calcMaxProfit(0,1,prices,dp);
    }
};