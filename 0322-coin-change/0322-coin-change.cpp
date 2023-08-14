class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans=INT_MAX;
      vector<int> prev(amount+1,0), curr(amount+1,0);
      int n=coins.size();
      for(int tar=0;tar<=amount;tar++){
        if(tar%coins[0]==0){
            prev[tar]=tar/coins[0];
        }
          else{
              prev[tar]=INT_MAX;
          }
      }
        
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=amount;tar++){
                int notTake=0 + prev[tar];
                
                int take=INT_MAX;
                if(coins[i]<=tar && curr[tar-coins[i]]!=INT_MAX){
                    take=1+curr[tar-coins[i]];
                }
                
                curr[tar]=min(take,notTake);
            }
            prev=curr;
        }
        
        if(prev[amount]>=INT_MAX){
            return -1;
        }
        
        return prev[amount];
        
    }
};