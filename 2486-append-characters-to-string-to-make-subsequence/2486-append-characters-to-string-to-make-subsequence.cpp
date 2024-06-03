class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        int j=0;
        int n=s.length();
        int m=t.length();
        
        int count=0;
        
        while(i<n && j<m){
            if(s[i]==t[j]){
                //increment both i and j pointer
                i++;
                j++;
            }
            else{
                //otherwise increment only i pointer in order to find the occurence of the next character of t in s
                i++;
            }
        }
        
       count=m-j; //count the remaining characters of t left to be appended in s
        //if m==j, signifies that all characters of t exist in s
        
        return count;
    }
};