class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int freq=n*0.25;
        
        int count=1;
        for(int i=1;i<n;i++){
            if(i>0 and arr[i]==arr[i-1]){
                count++;
                if(count>freq){
                    return arr[i];
                }
            }
            else{
                count=1;
            }
        }
        return arr[n-1];
    }
};

//class Solution {
// public:
//     int findSpecialInteger(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> candidates = {arr[n / 4], arr[n / 2], arr[3 * n / 4]};
//         int target = n / 4;
        
//         for (int candidate : candidates) {
//             int left = lower_bound(arr.begin(), arr.end(), candidate) - arr.begin();
//             int right = upper_bound(arr.begin(), arr.end(), candidate) - arr.begin() - 1;
//             if (right - left + 1 > target) {
//                 return candidate;
//             }
//         }
        
//         return -1;
//     }
// };
//Set n = arr.length.
// Create the array candidates with elements arr[n / 4], arr[n / 2], arr[3 * n / 4].
// Set target = n / 4.
// For each candidate in candidates:
// Calculate the leftmost index of candidate as left using binary search.
// Calculate the rightmost index of candidate as right using binary search.
// If right - left + 1 > target, return candidate.
// The code should never reach this point since it's guaranteed an answer exists. Return anything.