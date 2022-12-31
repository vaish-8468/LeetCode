class Solution {
public:
    
    int msb_pos(int i){
        if(i==0 ){
            return 0;
        }
        int i_msb=0;
        i=i/2;
        while(i>0){
            i=i/2;
            i_msb++;
        }
        
        return i_msb;
    }
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
    while(left!=0 && right!=0){
        int left_msb=msb_pos(left);
        int right_msb=msb_pos(right);
        if(left_msb!=right_msb){
            break;
        }
        else{
             ans+=pow(2,left_msb);
            left=left-pow(2,left_msb);
            right=right-pow(2,left_msb);
        }
       
    }
    return ans;
    }
};