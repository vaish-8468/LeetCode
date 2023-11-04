class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi=0;
        
        //find out the maximum time taken by any ant to reach the other end left
        for(int i=0;i<left.size();i++){
            int time=left[i];
            if(maxi<time){
                maxi=time;
            }
        }
        
        //find out the maximum time taken by any ant to reach the other end right
        for(int i=0;i<right.size();i++){
            int time=n-right[i];
            if(maxi<time){
                maxi=time;
            }
        }
        //return the maximum time taken i.e time taken by the slowest ant to cross the plank
        return maxi;
    }
};