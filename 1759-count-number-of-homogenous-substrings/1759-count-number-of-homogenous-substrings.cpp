class Solution {
public:
    int countHomogenous(string s) {
        int sum=0;
        int mod=1e9+7;
        
        int len=0; 
        //TC=O(n)
        //SC=O(1)
        //it counts the contribution of single character as 1
        //but suppose there is a subtring aaa -> which can be broken down into
        //a  aa  aaa  so we have 6 homogenous susbtrings for "aaa"
        //a  aa
        //a
        
        //similarly, aaaa is of len=4 and it can be further broken down into
        //a  aa   aaa aaaa  so we 10 homogenous substrings for "aaaa"
        //a  aa   aaa
        //a  aa
        //a
        
        for(int i=0;i<s.length();i++){
            if(i>0 && s[i]==s[i-1]){
                len+=1; //for it will add the contribution of the subtring as equal to the length of the substring
            }
            else{
                len=1; //otherwise counts the single contribution
            }
            sum=(sum+len)%mod;
           
        }
        
        return sum;
    }
};