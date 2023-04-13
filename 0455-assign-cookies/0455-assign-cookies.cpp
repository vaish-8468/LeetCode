class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count=0;
        int n=g.size();
        int j;
        for(int i=0;i<n;i++){
            j=0;
            while(j<s.size()){
                if(s[j]>=g[i]){
                    count++;
                    s[j]=0;
                    break;
                }
                j++;
            }
        }
        return count;
    }
};