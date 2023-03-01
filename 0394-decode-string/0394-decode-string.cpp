#include<bits/stdc++.h>
class Solution {
public:
    string decodeString(string s) {
        std::deque<char> stack;
        if(s.length()==1 && isdigit(s[0])){
            return "";
        }

        for (char c : s) {
            if (c == ']') {
                // extract the characters inside the brackets
                std::string stri;
                while (stack.front() != '[') {
                    stri = stack.front() + stri;
                    stack.pop_front();
                }
                stack.pop_front();

                // extract the number before the brackets
                std::string k;
                while (!stack.empty() && isdigit(stack.front())) {
                    k = stack.front() + k;
                    stack.pop_front();
                }

                // repeat the characters k times and push them back to the stack
                int repeat = std::stoi(k);
                for (int i = 0; i < repeat; i++) {
                    for (char c : stri) {
                        stack.push_front(c);
                    }
                }
            } else {
                stack.push_front(c);
            }
        }

        // construct the decoded string from the stack
        std::string result;
        for (char c : stack) {
            result = c+result;
        }
        return result;
    }
};
