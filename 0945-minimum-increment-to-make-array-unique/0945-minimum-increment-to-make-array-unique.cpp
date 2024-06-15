class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
       //T.C : O(nlogn)
      //S.C : O(1)
        
        sort(nums.begin(),nums.end());
        int moves=0;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                nums[i]+=1;
                moves+=1;
            }
            else if(nums[i]<nums[i-1]){
                int diff=nums[i-1]-nums[i]+1;
                moves+=diff;
                nums[i]+=diff;
            }
        }
        
        
        
        //Approach-2 (Using Counting Sort)
        //T.C : O(n+maxVal)
        //S.C : O(n+maxVal)

//         int n = nums.size();
//         int maxElement = 0;
//         int moves = 0;

//         for (int val : nums) {
//             maxElement = max(maxElement, val);
//         }

//         vector<int> count(n + maxElement, 0);

//         for (int val : nums) {
//             count[val]++;
//         }

//         for (int i = 0; i < count.size(); i++) {
//             if (count[i] <= 1) continue;

//             int extra = count[i] - 1;
//             count[i + 1] += extra;
//             count[i] = 1;
//             moves += extra;
//         }
        

        return moves;
        // 1 1 2 2 3 7
        // 4 1 5 2 3 7
    }
};