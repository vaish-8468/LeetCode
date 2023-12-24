class Solution {
public:
    int minOperations(string s) {
        int start0 = 0; //string started with 0
        int start1 = 0; //string started with 1
        
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    start1++; //since string started with 1 and s[i] is mismatched
                } else {
                    start0++;
                    //since string started with 0, s[i] is mismatched
                }
            } else {
                if (s[i] == '1') {
                    //if string started with 1 , then all odd position should store 0, therefore, s[i] is mismatched
                    start1++;
                } else {
                     //if string started with 0 , then all odd position should store 1, therefore, s[i] is mismatched
                    start0++;
                }
            }
        }
        
        return min(start0, start1);
    }
};