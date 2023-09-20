class Solution {
public:
    int minOperations(vector<int>& nums, int x) {     
        int n    = nums.size();
        int sum  = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        //store the prefix sum along with the array
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            mp[sum] = i;
        }
        if(sum < x)
            return -1; //not possible to reduce x coz elements are not sufficient enough
        
        int restSum  = sum-x; //find the longest subarray with Sum restSum
        int longest  = INT_MIN;
        
        sum = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            //check if the rest of the sum already exists in the map i.e can be achieved from the elements
            if(mp.count(sum-restSum)) {
                longest = max(longest, i-mp[sum-restSum]);//store the lenegth of the maximum subarray
            }
        }
        
        return longest==INT_MIN?-1:n-longest; //return the total len - longest subarray len to give min number of operations
    }
};