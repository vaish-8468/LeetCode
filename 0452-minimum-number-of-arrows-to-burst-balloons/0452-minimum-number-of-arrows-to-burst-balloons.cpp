class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int n=points.size();
        sort(points.begin(),points.end());
        int count=1;
        vector<int> prev=points[0];
        for(int i=1;i<n;i++){
           int currS=points[i][0];
           int currE=points[i][1];
            int prevS=prev[0];
            int prevE=prev[1];
            
            if(currS>prevE){
                //no overlapping
                //increment the arrow count
                count++;
                //update prev as curr
                prev=points[i];
            }
            else{
                //overlapping case
                //find the overlapping interval and check if any other point overlaps with this interval
                prev[0]=max(prevS,currS);
                prev[1]=min(prevE,currE);
            }
            
        }
        return count;
        
    }
};