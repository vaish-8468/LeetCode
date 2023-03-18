class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int i=0;
        int minLength = min(strs[0].size(),strs[n-1].size());
        sort(strs.begin(),strs.end());
        //sorts the array according to string length
        cout<<strs[0];
        string first=strs[0];
        string last=strs[n-1];
        //compares first and last array element and increment the i
        while(i<minLength && first[i]==last[i]){
            i++;
        }
        return first.substr(0,i);
        //returns the common substring
    }
};