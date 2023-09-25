class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> st;
        
        for(auto i: s){
            st[i]++;
        }
                                         
            char extra=' ';
        for(auto i:t){
            if(st.find(i)!=st.end() && st[i]!=0){
                st[i]--;
            }
            else{
                extra=i;
            }
        }
        
        return extra;
        
    }
};