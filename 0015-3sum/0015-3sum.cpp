class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //return only unique triplets irrespective of their number of occurences
        /***
        //BRUTE FORCE
        //use three for loops from index [0,n-1], [i+1,n-1] and [j+1,n-1] respectively
        //we'll sort the triplet and store them in the set to verify if the same triplet exists or not
        int n =nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> v={nums[i],nums[j],nums[k]};
                        sort(v.begin(),v.end());
                        st.insert(v);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        //TC=O(n^3+nlogn)
        //SC=O(2*no. of triplets)
        
        return ans; ***/
        
        
        /***
        //BETTER APPROACH
        // third element is written as a negative sum of the two elements and we'll try to search it in the set 
        //if the sum does not exists we'll add it into the set
        
        int n=nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++){
             set<int> hash; //to store the elements with the desired sum
             //set is responsible for filtering out the duplicates
            for(int j=i+1;j<n;j++){
                int third_ele=-(nums[i]+nums[j]);
                if(hash.find(third_ele)!=hash.end()){
                    vector<int> temp={nums[i],nums[j],third_ele};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hash.insert(nums[j]);      //log(n) time
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
        //GIVES TLE
        //TC=O(n^2*log(n))
        //SC=O(n)+2*O(no of triplets)
        
        ***/
        
        
        //OPTIMAL APPROACH
        //we'll sort the array first
        // two-pointer approach
        //we'll use three pointers i,j and k such that i points to the zeroth index
        //j points to the next index to i
        //k points to the last index
        //now we calculate the sum and if sum is found to be less than 0, we'll increment jth pointer since
        // the array is sorted otherwise if sum is found to be greater than 0, we'll decrement k,
        //therefore, i will serve asthe starting index, j as the middle and k as the last
        //we'll keep incrementing/decrementing j and k respectively until k>j
        //now our next ith index will be next first occurence of another element
        // the above approach will be applied for every ith index upto n
        //store the triplet in the vector
        
        //TC=O(nlogn+(n*n))  //sorting+(for*while) worst case
        //SC=O(no.of triplets) it's not the extra space but the space for returniing the answer
        
        vector<vector<int>> ans;
        int n=nums.size();
        //sort the vector
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
                //reach to the last occurence in order to avoid duplicates
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    //found the triplet
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    //increment/decrement j/k respectively to their last occurence such that no triplet is duplicated
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                    
                }
            }
        }
        
        return ans;
        
        
    }
};