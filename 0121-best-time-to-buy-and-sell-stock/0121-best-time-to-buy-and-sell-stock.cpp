#include <bits/stdc++.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int minp=prices[0];
        int profit=0;
        for(int i=0;i<prices.size();i++){
            
            profit=max(prices[i]-minp,profit);
            minp=min(prices[i],minp);
            
        }
        return profit;
                
        }
        
        
    
};

//   int lsf = INT_MAX;
//         int op = 0;
//         int pist = 0;
        
//         for(int i = 0; i < prices.size(); i++){
//             if(prices[i] < lsf){
//                 lsf = prices[i];
//             }
//             pist = prices[i] - lsf;
//             if(op < pist){
//                 op = pist;
//             }
//         }
//         return op;