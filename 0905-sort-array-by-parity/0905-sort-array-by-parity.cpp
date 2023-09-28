class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
      sort(nums.begin(), nums.end(),[&](const int& a, const int& b){
          return a%2<b%2;  //when a is even and b is odd--> 0<1 ,return a
                            //when b is even and a is odd--> 1<0, return b 
      }) ; 
        return nums;
    }
}; 