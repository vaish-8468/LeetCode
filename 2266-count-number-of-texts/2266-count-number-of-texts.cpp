class Solution {
public:
    int countTexts(string pressedkeys) {
        int n=pressedkeys.length();
        vector<int> dp(n+1,0);//since we'll be judging till the length of the string and one additional space is required for 0th index
        int mod=1e9+7;
        
        dp[0]=1; //one way for empty string
        
        //dp states here is length of the string
        //empty string is already considered , hence we'll start from the length 1
        for(int i=1;i<=n;i++){
            //i is the length
            dp[i]=dp[i-1]%mod; //previous length will always contribute to the current state as a new character has been added to the previous combination 
            char ch=pressedkeys[i-1];
            //now we check for the occurence for more than one time of the previous element
            if(i>=2 && pressedkeys[i-2]==ch){
            dp[i]=(dp[i]+dp[i-2])%mod;//ways of upto second index will also be counted
            }
            else{
                continue; //otherwise move over to the next previous index
            }
            if(i>=3 && pressedkeys[i-3]==ch){
                dp[i]=(dp[i]+dp[i-3])%mod; //ways of upto third index will also be counted
            }
            else{
                continue; //otherwise move over to the next previous index
            }
            if( (ch=='7' || ch=='9') && i>=4  && pressedkeys[i-4]==ch){
                dp[i]=(dp[i]+dp[i-4])%mod; //since there are four letters for 7 and 9
                //we check for the fourth occurence also
            }
            //we are simply adding up the possibilities of lower length strings as any new string will differ only in one letter from the previously calculated strings lower length
        }
        
        return dp[n]%mod; //since we've been asked for the number of ways for string of length n
    }
};