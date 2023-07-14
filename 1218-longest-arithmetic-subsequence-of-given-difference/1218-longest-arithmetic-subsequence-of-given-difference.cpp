class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int> mp; //to keep a record of the previous elements of ith index which have contributed to the subsequence of common difference 
        
        //{ith element: ;length of subsequence till ith element}
        int n=arr.size();
        int result=0;
        for(int i=0;i<n;i++){
            int prevState=arr[i]-difference; //store a-d element
            if(mp.find(prevState)==mp.end()){ //if a-d doesn't exists then no previous state to ith element contribute in the subsequence
                mp[arr[i]]=1; //count only the present element to be a part of the subsequence
            }
            else{ 
                mp[arr[i]]=mp[prevState]+1; //otherwise add 1 to the length of the existng subsequence since the previous state has been found which contributes to the subsequence
            }
            
            result=max(result,mp[arr[i]]); //store the max of the result
        }
        
        return result;
    }
    
    //TC=O(N)
    //SC=O(N)
    //https://www.youtube.com/watch?v=OHxwaAbO1A8
};