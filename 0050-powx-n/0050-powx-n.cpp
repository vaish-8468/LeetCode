class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        double ans=1.00000;
        if(N==0){
            return 1.0;
        }
        if(N==0){
            return 0.0;
        }
        if(N<0){
            N=-1 * N;
            x=1.0 / x;
        }
        
            while(N){
                if(N%2==1){
                    ans=ans*x;
                    N-=1;
                }
                x=x*x;
                N=N/2;
            }
        
       
        return ans;
    }
};