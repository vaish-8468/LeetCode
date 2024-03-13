class Solution {
public:
    int pivotInteger(int n) {
        if(n==1){
            return 1;
        }
        int sumEnd= n*(n+1)/2;
        int ans=-1;
        int sumStart=0;
        
        for(int i=1;i<n;i++){
            if(sumEnd==sumStart+i){
                ans=i;
            }
            sumEnd-=i;
            sumStart+=i;
        }
        
        return ans;
    }
};