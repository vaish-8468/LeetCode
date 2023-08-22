class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        
        string ans="";
        
        while(columnNumber>0){
            columnNumber-=1;;   //since the numbers would start from 0 since in terms of base, we start from 0
            ans+=(char)(columnNumber%26+'A');
            
            columnNumber/=26;
            
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        /*
        Subtract 1 from N. Now, N = 2001. Take N modulo 26 and convert the result to the corresponding position in the alphabet. 2001 % 26 = 25, which corresponds to Z, since we start with A = 0.
        
Initialize an empty string ans which would store the column title.

Do the following as long as columnNumber is greater than 0:

Subtract 1 from the columnNumber

Find the character corresponding to columnNumber % 26 and append it to the ans in the end.

Assign columnNumber to columnNumber / 26.

Reverse the string columnNumber and return it.
        
        
        
        */
        
    }
};