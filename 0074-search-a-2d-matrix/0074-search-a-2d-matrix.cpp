class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0){
            return false;//empty matrix
        }
        int start=0;
        int end=m*n-1;
        //we'll use binary search
        bool ans=false;
        while(start<=end){
            long long mid=start+(end-start)/2;//assuming the matrix to be a 2D array
            int row=mid/n;
            int col=mid%n;
            //finds the middle index in a matrix
            if(target==matrix[row][col]){
             ans=true;//if found, return true
                break;
        }
            else{
                if(target<matrix[row][col]){
                    end=mid-1;//element lies in the left of the assumed array
                }
                else{
                    start=mid+1; //element lies in the right of the assumed array
                }
            }
        }
        return ans;
    }
};