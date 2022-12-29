class Solution {
public:
    int count_(int n){
       int count=0;
        while(n>0){
             int last_bit=n&1;
             count+=last_bit;
             n=n>>1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(count_(i));
        }
        return ans;
    }
};