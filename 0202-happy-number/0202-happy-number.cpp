#include<bits/stdc++.h>
class Solution {
public:
    bool isHappy(int n) {
        int num=n;
        int sum=0;
        unordered_set<int> st;
        //set count checks for the presence of a number in a set, if already present signifies inf loop
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
        //returns true if num==1
    }
};

