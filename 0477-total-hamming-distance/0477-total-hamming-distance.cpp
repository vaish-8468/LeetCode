class Solution {
public:
  

    int totalHammingDistance(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for(int i=0;i<32;i++){
            int count_1=0;
            for(int x:nums){
                count_1+=((x>>i)&1);
            }
            res+=(count_1*(n-count_1));
        }
        return res;
    }
};