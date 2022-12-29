class Solution {
public:
    int bitcount(int n){
        int count=0;
        while(n>0){
            n=n&(n-1);
            count++;
        }
        return count;
    }
   
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> res;
        vector<pair<int,int>> count_bit;
        for(int i=0;i<arr.size();i++){
            count_bit.push_back({bitcount(arr[i]),arr[i]});
        }
        sort(count_bit.begin(),count_bit.end());
        for(auto val: count_bit){
            res.push_back(val.second);
        }
       return res;
          
    }
};