class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        int ans=0;
        int prevMax=0;
        //both the variables deal with neededTime vector only
        for(int i=0;i<n;i++){
         if(i>0 && colors[i-1]!=colors[i]){
             prevMax=0;
         }
        int curr=neededTime[i];
        ans+=min(prevMax,curr);
        prevMax=max(prevMax,curr);
        }
        
        return ans;
    }
};