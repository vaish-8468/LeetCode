class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size()){
            //chances of rotation of an array
            return *max_element(arr.begin(),arr.end());
        }
        
        int maxi=*max_element(arr.begin(),arr.end());
    
        
        int n=arr.size();
        int ans=arr[0];
        int count=0;
        
        //since k<n , therefore, no rotations needed
        for(int i=1;i<n;i++){
            //k consecutive acchievements or maximum element reached zeroth index
            if(count>=k || maxi==ans){
                return ans;
            }
            
            if(arr[i]>ans){
                ans=arr[i];
                count=1;
            }
            else{
                count++;
            }
         
        }
        return ans;
    }
};