class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> altitudes(n+1); //a vector to store the altitudes
        altitudes.push_back(0); //since it is strating from 0
        
        for(int i=0;i<n;i++){
            int altitude=altitudes.back()+gain.at(i); //adding the net gain in the altitude to find the next altitude
    
            altitudes.push_back(altitude);
        }
        
        return *max_element(altitudes.begin(),altitudes.end());  //the maximum of all will be the altitude point 
    }
};