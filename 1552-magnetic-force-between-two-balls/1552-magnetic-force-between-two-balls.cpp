class Solution {
public:
    
      int placeTheBalls(vector<int>& positions,int mid, int new_m){
            
            new_m--;
            //placed the first ball
            int left=0;
            for(int i=1;i<positions.size();i++){
                if(positions[left]+mid<=positions[i]){
                    new_m--;
                    left=i;
                }
                if(new_m==0){
                    return 0;
                }
            }
            return new_m;
        }
    
    
    int maxDistance(vector<int>& positions, int m) {
        //place the balls such that they are equidistant  and force required between them is maximum
        int n=positions.size();
        sort(positions.begin(),positions.end());
        
        int left=1; //min force required
        int right=positions[n-1]-positions[0]; //max force required
        int ans=1;
   
        
        while(left<=right){
            int mid=left+(right-left)/2;
            int new_m=placeTheBalls(positions,mid,m);
            if(new_m>0){
                //decrease the force
                right=mid-1;
                
            }
            else{
                //increase the force
                ans=max(ans,mid);
                left=mid+1;
            }
        }
        return ans;
    }
};