class Solution {
public:
    int t[301][11]; //as per the contraints given
    int subPartitions(int idx, int d, vector<int>& jobDifficulty){
        if(d==1){
            //only one day is left
            //alll the remaining jobs needs to be completed
            //max of all jobs would account for the difficulty of this day
            return *max_element(jobDifficulty.begin()+idx,jobDifficulty.end());            
        }
        if(t[idx][d]!=-1){
            return t[idx][d];
        }
        
        int maxD=jobDifficulty[idx];
        int res=INT_MAX;
        
        for(int i=idx;i<=jobDifficulty.size()-d;i++){
            maxD=max(maxD,jobDifficulty[i]);
            res=min(res,maxD+subPartitions(i+1,d-1,jobDifficulty));
        }
        
        return t[idx][d]=res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n){
            return -1;
            //not enough job for each day
        }
        if(d==n){
            return accumulate(jobDifficulty.begin(),jobDifficulty.end(),0);
        }
        
        memset(t,-1,sizeof(t));
        
        return subPartitions(0,d,jobDifficulty);  
    }
};