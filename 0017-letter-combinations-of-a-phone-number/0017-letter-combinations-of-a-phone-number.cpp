class Solution {
public:
    //backtracking is used
    map<char,string> mp{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    //map is initialized with digits and letters
    vector<string> result;
    //global variable
    void checkPossibility(int index, string &s, string &permutation){
        //base case
        //if the all the characters of the string is traversed, the formed string is added in the vector
    if(index>=s.length()){
    result.push_back(permutation);
        return;
    }
        //extract the digit
        char ch=s[index];
        //extract the corresponding letters
        string str=mp[ch];
        //run a loop to traverse all the letters for a paricular number
        for(int i=0;i<str.length();i++){
            //take
            permutation.push_back(str[i]);
            //move over to the next possible character of the next digit 
            checkPossibility(index+1,s,permutation);
            //backtrack
            permutation.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        string permutation="";
        checkPossibility(0,digits,permutation);
        return result;
    }
};