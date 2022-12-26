class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        if(s.length()==1){
            return 1;
        }
        int l=0;
        int j=0,i=0;
        unordered_map<char,int> mp;
        for(;i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=1;
                
            }
            else{
               l=max(l,i-j);
                while(j<i){
                    if(s[j]!=s[i]){
                        mp.erase(s[j]);
                    }
                    else{
                        j++;
                        break;
                    }
                    j++;
                }
            }
            
            
        }
        l=max(l,(i-j));
        return l;
        
    }
};