class Solution {
public:
   
    
    int fib(int n) {
        int memo[n+2];
        memset(memo,0,sizeof(memo));
        memo[0]=0;
        memo[1]=1;
        
        for(int i=2; i<=n;i++){
        
        memo[i]=memo[i-1]+memo[i-2];
    
        }
        return  memo[n];
    }
};