class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
     
        for(int l = 1; l <= n/2; l++) {  //Iterate over all the prefix substrings of length i = 1 to n / 2
            
            if(n%l == 0) {
                //If i divides n, we declare an empty string pattern. Use an inner loop that iterates n / i times to concatenate the substring formed from the first i characters of s
                int times = n/l;
                
                string pattern   = s.substr(0, l);
                string newStr = "";
                while(times--) {
                    newStr += pattern;
                }
                
                if(newStr == s)
                    //If pattern equals s, we return true.
                    return true;
            }
            
        }
        
        return false;
    
    }
};