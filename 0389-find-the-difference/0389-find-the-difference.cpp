class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> st;
        
        for(auto i: s){
            st[i]++;
            //adding the character and its freq into the map
        }
                                         
            char extra=' ';
        for(auto i:t){
            if(st.find(i)!=st.end() && st[i]!=0){
                //deducting frequency of all those who are present in s
                st[i]--;
            }
            else{ //when the char is not present in s or even though it's present but it does not hold any frequency in s, that will be our answer
                extra=i;
            }
        }
        
        return extra;
        
    }
};