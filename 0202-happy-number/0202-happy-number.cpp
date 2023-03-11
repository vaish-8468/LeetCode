#include<bits/stdc++.h>
class Solution {
public:
    bool isHappy(int n) {
        int num=n;
        int sum=0;
        unordered_set<int> st;
        while(num!=1 && !st.count(num)){
        st.insert(num);
        while(num>0){
            sum+=pow(num%10,2);
            num=num/10;    
        }
            num=sum;
            sum=0;
        }
        return num==1;
    }
};

