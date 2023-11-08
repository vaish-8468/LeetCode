class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy && t==1){
            return false;
        }
        
        int vertical=abs(fy-sy);
        int horizontal=abs(fx-sx);
        
        if(t>=max(vertical,horizontal)){
            return true;
        }
        return false;
    }
};