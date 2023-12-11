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