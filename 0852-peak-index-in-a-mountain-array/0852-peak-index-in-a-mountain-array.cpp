class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left=0;
        int right=arr.size()-1;
        //we'll use binary searchmethod which would reduce the time complexity to O(N)
        long long mid;
        while(left<right){//the index at which left==right will be our ans
            mid=left+(right-left)/2;
            
            if(arr[mid]<arr[mid+1]){
                //sequence is still increasing hence discard the left region till mid
                left=mid+1;
            }
            else{
                right=mid; //otherwise discard the right region till mid+1 and check within left and mid
            }
        }
        
        return left;
    }
};