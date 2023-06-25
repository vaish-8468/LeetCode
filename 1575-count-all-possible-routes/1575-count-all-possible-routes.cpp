class Solution {
public:
    int mod=1e9+7;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel, vector<vector<int>>& dp){
        if(fuel<0){
            return 0; //when you run out of fuel
        }
        if(dp[start][fuel]!=-1){
            return dp[start][fuel]; //if the route between the cities have already been counted
        }
        int res=0;
        if(start==finish){
            res++; //on reaching the destination, add the path to the count
        }
        for(int i=0;i<locations.size();i++){
            if(i==start || abs(locations[i]-locations[start])>fuel){ //as acc to the condition i!=j or if the fuel to be spend is larger than the fuel we have
                continue;
            }
            res+=countRoutes(locations, i, finish, fuel-abs(locations[i]-locations[start]), dp); 
            res=res%mod;
            
        }
        
        return dp[start][fuel]=res%mod; //store the number of routes for that particular path wth fuel
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        //graph theory question
        int n=locations.size();
        vector<vector<int>> dp(n,vector<int>(fuel+1,-1));
        //here dp states used are start and fuel
        return countRoutes(locations,start,finish,fuel,dp);
        
    }
};