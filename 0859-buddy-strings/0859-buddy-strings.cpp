class Solution {
public:
    bool checkDuplicate(string s){
        unordered_map<char,int> mp;
        for(auto &ch :s){
            if(mp.find(ch)==mp.end()){
                mp[ch]=1;
            }
            else{
                return true; //if freq of any char is more than 1, then duplicate exists
            }
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()){
            return false; //if the length of the strings are not equal
        }
        if(s==goal){
            if(checkDuplicate(s)){ //if the strings are equal but if there exist a pair of duplicate then we 
                return true; //we've a chance of one swap, hence will return true if found
            }
            return false; //no duplicates indicate that no chance of swap is possible
        }
        vector<int> index;  //define a vector for storing the index where string characters are unequal
        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[i]){  //store the index where found unequal
                index.push_back(i);
            }
        }
        if(index.size()!=2){ //since the contraint is we have only one chance of a swap
            return false; //if found more tha two indexes then we'll have to perform more than 1 number of swaps
            //hence false
        }
        swap(s[index[0]],s[index[1]]);  //if srings vary only for two characters, then swap their indices
        if(s==goal){
            return true; //if after swapping, strings become equal, then return true
        }
        
        return false;  //if no condition is satisfied, return false at the end
    }
};