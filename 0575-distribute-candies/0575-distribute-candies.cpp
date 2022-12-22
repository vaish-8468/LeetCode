#include<bits/stdc++.h>
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
     unordered_map<int, int> candy;
        int count = 0;
        for (int i = 0; i < candyType.size(); i++) {
                   if (!candy[candyType[i]]) {
                count++;
                if (count == candyType.size() / 2) {
                    return candyType.size() / 2;
                }
            }
         
            candy[candyType[i]]++;
        }
        return count;}
};