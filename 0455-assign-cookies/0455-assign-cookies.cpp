class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count=0;
        int j=0,i=0;
        while(i<g.size() && j<s.size()){
                if(s[j]>=g[i]){
                    count++;
                    s[j]=0;
                    i++;
                    j++; //increment both i and j since one child can have atmost 1 cookie and the assigned cookie cannot be given to somebody else
                }
            else{
                j++;  //keep incrementing the cookie if s[j]<g[i] i.e size of cookie is less than the min capacity of the child
            }
            
        }
        return count;  //TC=O(max(g.size(),s.size()))
    }
};