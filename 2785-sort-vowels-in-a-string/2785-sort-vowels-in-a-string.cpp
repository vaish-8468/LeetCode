class Solution {
public:
    
    bool checkVowel(char ch){  //TC=O(1)
        char chr=tolower(ch);
        if(chr=='a' || chr=='e' || chr=='i' || chr=='o' || chr=='u'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        string vowels="AEIOUaeiou"; //as per the ascii order
        int j=0;
        unordered_map<char,int> st;
        
        for(int i=0;i<s.length();i++){
            if(checkVowel(s[i])){
                st[s[i]]++; //insert all the existing vowels along with their frequency
            }
        }
        
        for(int i=0;i<s.length();i++){
            if(!checkVowel(s[i])){ //consonant
                continue;
            }
            else{
                //vowel
                while(st[vowels[j]]==0){ //move onto the next existing vowel in the given string
                    j++;
                }
                s[i]=vowels[j];
                st[vowels[j]]--;
            }
        }
        
        return s;
    }
};