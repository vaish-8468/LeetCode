class Solution {
public:
    
    int findTargetSumWays(vector<int>& arr, int d) {
    int n=arr.size();
    // Write your code here.
    //count the total sum
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    if((sum-d)<0 || (sum-d)%2){
        return false; //not possible to patition into subsets
    }
    //otherwise
    
    int target=(sum-d)/2;
    vector<int> prev(target+1,0), curr(target+1,0); //vector of sum upto target
    if(arr[0]==0){
        prev[0]=2; //two ways to get the sum=0
    }
    else{
        prev[0]=1; //only one way possible
    }
    if(arr[0]!=0 && arr[0]<=target){
        prev[arr[0]]=1; //only one way for non-zero element at index 0 to contribute to sum=0
    }
    for(int i=1;i<n;i++ ){
        for(int sum=0;sum<=target;sum++){
            int notTake=prev[sum];
            int take=0;
            if(arr[i]<=sum){
                take=prev[sum-arr[i]];
            }

            curr[sum]=(take+notTake);

        }
        prev=curr;
    }

    return prev[target];
    
}
};