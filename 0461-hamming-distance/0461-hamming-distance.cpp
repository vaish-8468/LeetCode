class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        int xor_=x^y;
        while(xor_>0){
            xor_=xor_&(xor_-1);
            xor_>>1;
            count++;
        }
        return count;
    }
};