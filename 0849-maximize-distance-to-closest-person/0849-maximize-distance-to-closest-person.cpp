class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        if(seats.size()==1){
            return 0;
        }
        int n=seats.size();
        
        vector<int> left(n,n);
        vector<int> right(n,n);
        
        int ans=0;
        for(int i=0;i<n;i++ ){
            if(seats[i]==1){
                left[i]=0;
            }
            else if(i>0){
                left[i]=left[i-1]+1;
            }
        }
        
        for(int j=n-1;j>=0;j--){
            if(seats[j]==1){
                right[j]=0;
            }
            else if(j<n-1){
                right[j]=right[j+1]+1;
            }
        }
        
        for(int i=0;i<n;i++){
            if(seats[i]==0)
                ans=max(ans,min(left[i],right[i]));
        }
        
        return ans;
    }
};