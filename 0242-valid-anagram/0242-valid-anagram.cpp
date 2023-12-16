class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int> mp;
        unordered_map<char,int> sp;
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        for(int i=0;i<t.length();i++){
            sp[t[i]]++;
        }
        if(mp==sp){
            return true;
        }
        return false;
    }
};