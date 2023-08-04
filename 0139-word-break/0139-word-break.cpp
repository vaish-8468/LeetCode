class Solution {
public:
    int n ;
   int DP[301];
    
    bool wordBreakHelperFunc(int index, string& s,unordered_set<string> st, int n){
        if(index>=n){
            return true; //1 represents true
            //word exists in the dictionary
        }
        
        if(DP[index]!=-1){
            return DP[index];
        }
        
        for(int i=1;i<=n;i++){
        //i reprents length
            string temp=s.substr(index,i); //extracts the substrring
            if(st.find(temp)!=st.end() && wordBreakHelperFunc(index+i,s,st,n) ){
                return DP[index]=true;
            }
        }
        
        return DP[index]=false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         int n=s.length();
        memset(DP,-1, sizeof(DP));
        unordered_set<string> st;
        //here DP states will be the length of the string
        
        //store the words in unordered set such that we need not to search for the word in the vector given
        for(auto& word:wordDict){
            st.insert(word);
        }
        
        return wordBreakHelperFunc(0,s,st,n);
        
    }
};