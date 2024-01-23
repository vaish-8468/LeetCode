class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        int count1=0;
        int count2=0;
        int left=0;
        int right=n-1;
        
        while(left<right){
            if(s[left]=='a' || s[left]=='e' || s[left]=='i' || s[left]=='o' || s[left]=='u' || s[left]=='A' || s[left]=='E' || s[left]=='I' || s[left]=='O' || s[left]=='U'){
                count1++;
            }
            if(s[right]=='a' || s[right]=='e' || s[right]=='i' || s[right]=='o' || s[right]=='u' || s[right]=='A' || s[right]=='E' || s[right]=='I' || s[right]=='O' || s[right]=='U'){
                count2++;
            }
        left++;
        right--;
        }
        
        if(count1==count2){
            return true;
        }
        
        return false;
        
        
       
    }
};