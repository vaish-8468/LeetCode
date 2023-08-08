//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        vector<int> dp(n+1,0);
        dp[1]=1; //only one way possible
        dp[2]=2; //again one way possible
        int mod=1e9+7;
        
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%mod; //since last two indexes will also contribute in determining the number of ways
        }
        
        return dp[n];
    }
        // your code here
    
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends