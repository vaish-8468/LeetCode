class Solution {
public:
    bool isPowerOfFour(int n) {
       if(n >0 && ((n&(n-1)) == 0) && !(n & 0xAAAAAAAA)){
           return true;
       }
        else{
            return false;
        }
    }
};