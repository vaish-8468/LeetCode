class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        
        map<int,int> mp;
        vector<int> vec; //stores all the unique occurences of arr1 wrt arr2
        
        for(auto x: arr2){
            mp[x]=0;
        }
        
        int x=n-1;
        for(int i=n-1;i>=0;i--){
            if(mp.find(arr1[i])!=mp.end()){
                mp[arr1[i]]++;
            }
            else{
                vec.push_back(arr1[i]);
                // arr1[x--]=arr1[i];
            }
        }
        sort(vec.begin(),vec.end());
        
        for(int i=vec.size()-1;i>=0;i--){
            arr1[x--]=vec[i];
        }
       
        for(int i=m-1;i>=0;i--){
            while(mp[arr2[i]]--){
                arr1[x--]=arr2[i];
            }
        }
        
        return arr1;
    }
};