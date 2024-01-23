class Solution {
public:
    bool CheckDuplicate(string& s1, string& s2){
        int arr[26]={0};
        for(char &ch: s1){
            if(arr[ch-'a']>0){
                //character repeated
                return true;
            }
            arr[ch-'a']++;
        }
        
        //now check the duplicates for string2
        for(char &ch: s2){
            if(arr[ch-'a']>0){
                return true;
                }
        }
        
        return false;
    }
    
    int helperFunc(int idx, vector<string>& arr, string temp,int n){
        if(idx>=n){
            return temp.length();
        }
        
        int include=0;
        int exclude=0;
        
        if(CheckDuplicate(arr[idx],temp)){
            exclude=helperFunc(idx+1,arr,temp,n);
        }
        else{
            //check the two cases
            exclude=helperFunc(idx+1,arr,temp,n);
            include=helperFunc(idx+1,arr,temp+arr[idx],n);
        }
        
        return max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        int n =arr.size();
       
        string temp="";
        return helperFunc(0,arr,temp,n);
        
    }
};