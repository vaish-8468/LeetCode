class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //find the length of the LCS
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        //now print the LCS and non_LCS elemnts in reverse order such that
        int i=n;
        int j=m;
        string ans="";
        
        while(i>0 && j>0){
            //str1 is along the row side and st2 is along the column side
            //c o l u m n
            //r
            //o
            //w
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1]; //take the element from any one of them once
                i--;
                j--; //decrement both the indices
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                //move towards the greater value
                //if row is changed
                //take the contribution of the last row elemnt and decrement the index of row
                ans+=str1[i-1];
                i--;
            }
            else{
                ans+=str2[j-1];
                j--;
            }
        }
        //at the end if any of the indices are not yet 0, taht means there cotribution in the supersequence is yet to be made
        
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        
        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        
        //reverse the string , since we are traversing from the end i.e bottom up approach
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};