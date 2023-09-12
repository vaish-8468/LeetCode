class Solution {
public:
    int minDeletions(string s) {
        //store the frquencies in a vector
        vector<int> freq(26,0);
        
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        
        //keep storing the unique frequencies in a set 
        //if the freq already exists in the set then keep decrementing it unless it becomes unique and count the number of decrements
        
        unordered_set<int> st;
        
        int ans=0;
        for(int i=0;i<26;i++){
            while(freq[i]>0 && st.find(freq[i])!=st.end() ){
                freq[i]--;
                ans++;
            }
            
            st.insert(freq[i]);
        }
        
        return ans;
    }
    //TC=O(1)
    //SC=O(n) bcoz of the set
};