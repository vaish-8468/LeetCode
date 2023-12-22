class Solution {
public:
    int maxi=INT_MIN;
    int count(int idx, string s){
        if(idx==s.length()){
            return 0;
        }
        
        int countzero=0;
        int countone=0;
        
        for(int i=0;i<idx;i++){
            if(s[i]=='0'){
                countzero++;
            }
        }
        
        for(int i=idx;i<s.length();i++){
            if(s[i]=='1'){
                countone++;
            }
        }
        maxi=max(maxi,countone+countzero);
        return count(++idx,s);
        
    }
    int maxScore(string s) {
        int co=count(1,s);
        
        return maxi;
    }
};