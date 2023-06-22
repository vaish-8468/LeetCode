class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int aheadnotbuy, aheadbuy, currbuy, currnotbuy;
        aheadnotbuy=aheadbuy=0;
        
        for(int i=prices.size()-1;i>=0;i--){
            //sell
            
            currnotbuy=max(prices[i]-fee+aheadbuy, 0+aheadnotbuy);
            
            //buy
            
            currbuy= max(-prices[i]+aheadnotbuy, 0+aheadbuy);
            
            aheadbuy=currbuy;
            aheadnotbuy=currnotbuy;
        }
        
        return aheadbuy;
    }
};