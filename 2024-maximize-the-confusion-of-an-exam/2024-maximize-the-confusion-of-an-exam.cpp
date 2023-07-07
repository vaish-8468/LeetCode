class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int size=answerKey.length();
        int left=0;
        int count=0;
        int ans=0;
        string s=answerKey;
        
        for(int i=0;i<size;i++){
            if(s[i]=='F'){
                count++;
            }
            while(count>k){
                if(s[left]=='F'){
                    count--;
                }
                left++;
            }
            ans=max(i-left+1,ans);
        }
        
        count=0;
        left=0;
        for(int i=0;i<size;i++){
            if(s[i]=='T'){
                count++;
            }
            
            while(count>k){
                if(s[left]=='T'){
                    count--;
                }
                left++;
            }
            ans=max(i-left+1,ans);
        }
        return ans;
    }
};