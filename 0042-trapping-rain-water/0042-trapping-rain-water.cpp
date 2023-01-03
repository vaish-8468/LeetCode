class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        if(n<=2){
            return 0;
        }
        // make two arrays of left highest and right highest and keep a record of the highest element till now at each position
        vector<int> left(n,0);
        vector<int> right(n,0);
        int heighest_left=0;
        int heighest_right=0;
       
        for(int i=0;i< height.size();i++){
            heighest_left=max(heighest_left,height[i]);
            left[i]=heighest_left;
            heighest_right=max(heighest_right,height[n-1-i]);
            right[n-1-i]=heighest_right;
        }
        int total=0;
        for(int i=0;i<height.size();i++){
            total+=(min(left[i],right[i])-height[i]);
        }
        return total;
    }
};