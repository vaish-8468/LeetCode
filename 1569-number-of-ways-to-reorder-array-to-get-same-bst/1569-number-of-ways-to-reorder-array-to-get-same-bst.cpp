class Solution {
public:
    
        
    int numOfWays(vector<int>& nums) {
    int n=nums.size();
    bino_coeff.resize(n+1);
    long long modulo= 1e9 +7;
    
    for(int i=0;i<n+1;i++){
        bino_coeff[i]= vector<int>(i+1,1); //initially each will have only one way
        for(int r=1;r<i;r++){
            bino_coeff[i][r]=(bino_coeff[i-1][r]+bino_coeff[i-1][r-1])%modulo; //formula for computation of nCr
        }
        }
 
        long long ans=dfs(nums,modulo);  //we'll calculate the number of ways for each subtree
        return (ans%modulo-1)%modulo;
    }               //ans-1 ,since one way is already given in the question
    
     vector<vector<int>> bino_coeff; //this vector will store the number of ways for each overlapping subproblem
    
    int dfs(vector<int>& nums, long long modulo){
        int n=nums.size();
        if(n<=2){ //if tjhe size of the subtree is 2 then number of ways will be 1
            return 1;
        }
        
        vector<int> right;
        vector<int> left;
        
        for(int i=1;i<n;i++){
            if(nums[i]<nums[0]){
                left.push_back(nums[i]);  //add the element to the vector if its less than the root 
            }
            else{ //otherwise
                right.push_back(nums[i]);
            }
        }
            
            long long left_res=dfs(left, modulo)%modulo;  //since the answer might be large hence each will be calculated by modulo
            long long right_res=dfs(right,modulo)%modulo;
            
            int left_len=left.size();
            int right_len=right.size();
            
            return (((bino_coeff[n-1][left_len] *left_res) %modulo )*right_res% modulo);
        }                //n-1Cr                  //ways for left      //ways for right
    
};