class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        long long left=1;
        long long right=1e7;
        int ans=-1;
        //we'll use binary search here and for every speed check whether we can reach the destination within the specified
        //linear search would take O(N*1e7)
        //hence we can use binary search
        while(left<=right){
            int mid=left+(right-left)/2;
            double res=0.0;
            int i;
            
            //check for the speed if it enables us to reach destination or not
            for(i=0;i<dist.size()-1;i++){
              double time=((double)dist[i]/(double)mid);
                res+=ceil(time);
            }
            
            res+=((double)dist[i]/(double)mid);
            
            if(res<=hour){
                //there's possibility of minimizing the speed
                ans=mid;
                right=mid-1;
            }
            else{
                //speed has to be increased
                left=mid+1;
            }
        }
        
        return ans;
    }
};