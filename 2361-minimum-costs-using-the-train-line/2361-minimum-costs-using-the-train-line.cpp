class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        vector<long long> res;
        int n=regular.size();
        //two dp used
        vector<long long> regularDP(n,0);
        vector<long long> expressDP(n,0);
        //dp states used are cities
        regularDP[0]=min(regular[0],express[0]+expressCost); //since there will be two ways to reach i and minimum amongst them will be chosen
        expressDP[0]=express[0]+expressCost; //since there is only one way to reach the express stop i
        res.push_back(min(regularDP[0],expressDP[0]));//push the min route for 0->1
        for(int i=1;i<regular.size();i++){
            regularDP[i]=min(regularDP[i-1]+regular[i],expressDP[i-1]+regular[i]);
            expressDP[i]=min(expressDP[i-1]+express[i],regularDP[i-1]+express[i]+expressCost);
            
            res.push_back(min(regularDP[i],expressDP[i])); //consider the minimum cost out of two options
        }
        
        return res;
    }
};