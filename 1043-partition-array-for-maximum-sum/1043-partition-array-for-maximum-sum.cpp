class Solution {
public:
    int t[501];
    int partition(int idx, vector<int>& arr, int k){
        if(idx>=arr.size()){
            return 0;
        }
        if(t[idx]!=-1){
            return t[idx];
        }
        
        int res=0;
        int curr_max=0;
        for(int j=idx;j<arr.size() && j-idx+1<=k;j++){
            curr_max=max(curr_max,arr[j]);
            res=max(res,(j-idx+1)*curr_max+partition(j+1,arr,k));
        }
        
        return t[idx]=res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(t,-1,sizeof(t));
        return partition(0,arr,k);
        
    }
};