class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy(nums);
        sort(copy.begin(),copy.end());
        int i=0;
        int j=nums.size()-1;
        while(i<=nums.size()-1 && (nums[i]==copy[i])){
            i++;
        }
        while(j>=0 && (nums[j]==copy[j])){
            j--;
        }
              if(i==nums.size()){
                  return 0;
              }
        return j-i+1;
    }
};