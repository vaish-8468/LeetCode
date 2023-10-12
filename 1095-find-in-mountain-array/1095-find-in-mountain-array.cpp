/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        if(mountainArr.length()<3){
            return -1;
        }
        
        int left=0;
        int right=mountainArr.length()-1;
        int idx=-1;
        //we'll use binary searchmethod which would reduce the time complexity to O(logN)
        long long mid;
        while(left<right){//the index at which left==right will be our ans
            mid=left+(right-left)/2;
            
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                //sequence is still increasing hence discard the left region till mid
                left=mid+1;
            }
            else{
                right=mid; //otherwise discard the right region till mid+1 and check within left and mid
            }
        }
        
        int peak=left;
        
        
        //to implement binary search in first increasing half
        int end=peak;
        int start=0;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(mountainArr.get(mid)==target){
                idx=mid;
                break;
            }
            
            if(mountainArr.get(mid)<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        if(idx!=-1){
            return idx;
        }
        
        
        //to mplement binary search in decresing half if not found in first half
        
        
        start=peak;
        end=mountainArr.length()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(mountainArr.get(mid)==target){
                idx=mid;
                break;
            }
            
            if(mountainArr.get(mid)<target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
        
        return idx;
    }
};