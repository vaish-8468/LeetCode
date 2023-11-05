class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      /***  left rotate the array
        number of rotations we have to make to retrieve the original state from rotated           //state would be k%arr.size()
        any number of rotations less than the size of the array can be easily done
        
        BRUTE FORCE
        store the first k elements in temp vector
        then perform left shift of the rest k+1 elements by i-k step towards left
        
        int n=nums.size();
        vector<int> temp;
        k=k%n;
        
        LEFT ROTATING ARRAY
        //store
        O(k)
        for(int i=0;i<k;i++){
            temp.push_back(nums[i]);
        }
        
        //shift
        O(n-k)
        for(int j=k;j<n;j++){
            nums[j-k]=nums[j];
        }
        
        //put back
        O(k)
        for(int i=n-k;i<n;i++){
            nums[i]=temp[i-(n-k)];
        }
        total = O(k+(n-k)+k)=O(n+k)
        SC=O(k)
        
        OPTIMAL APPROACH
        reverse the first k elements, reverse the rest n-k elements
        reverse the whole array all at once
        given: 1,2,3,4,5,6,7 k=3
        3,2,1 | 7,6,5,4
        4,5,6,7,1,2,3 //left rotated array by k steps
        TC=O(2n) SC=O(1)
        
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());
        
        ***/
        
      /***  
        RIGHT ROTATING ARRAY (BRUTE FORCE)
        
        store
        for(int i=n-k;i<n;i++){
            temp.push_back(nums[i]);
        }
        
        //shift
        for(int j=n-k-1;j>=0;j--){
            nums[j+k]=nums[j];
        }
        
        //put back
        for(int i=0;i<k;i++){
            nums[i]=temp[i];
        }
        ***/
        //OPTIMAL APPROACH  TC=O(2n) SC=O(1)
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.begin()+n-k);
        reverse(nums.begin()+n-k,nums.end());
        reverse(nums.begin(),nums.end());
        return ;
        
        
    }
};