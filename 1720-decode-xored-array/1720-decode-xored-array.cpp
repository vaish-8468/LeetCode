class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> arr{first};
        
        for(auto x: encoded){
            arr.push_back(first^=x);
        }
        return arr;
    }
};