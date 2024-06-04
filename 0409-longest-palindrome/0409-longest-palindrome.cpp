class Solution {
public:
    int longestPalindrome(string s) {
          int Count = 0;
        unordered_map<char, int> mp;
        for(char ch : s) {
            mp[ch]++;
            if (mp[ch] % 2 == 1)
                //count characters having odd frequency
                Count++;
            else    
                Count--;
            //decrement odd count since even frequency character encountered
        }
        if (Count > 1)
            return s.length() - Count + 1;
        //n-(count of odd frequency characters)+1(count the contribution of any one odd frequency character)
        return s.length();

    }
};