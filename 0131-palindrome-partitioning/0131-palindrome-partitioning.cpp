class Solution {
public:
    
    bool checkPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
                //start and end will keep incrementing and decrementing simultaneously
            }
        }
        return true;
    }
    
    void helperfunc(int start, string s, vector<vector<string>>& ans, vector<string>& strings){
        if(start==s.length()){
            ans.push_back(strings);
            //when the index reaches the end of the string
        }
        for(int i=start;i<s.length();i++){
            if(checkPalindrome(s,start,i)){
                strings.push_back(s.substr(start, i-start+1));
                
                //recursively call the function for sub-cases
                helperfunc(i+1,s,ans,strings);
                
                //backtracking
                strings.pop_back();
                
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> strings;
        
        //starting from zeroth index
        helperfunc(0,s,ans,strings);
        return ans;
        
    }
};