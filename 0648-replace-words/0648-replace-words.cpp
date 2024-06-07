class Solution {
public:
    
    string findRoot(string word, set<string> st){
        for(int i=1;i<=word.length();i++){
            string root=word.substr(0,i);
                if(st.count(root)==1){
                    return root;
                }
            }
        return word;
    }
    
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        //find the words from the sentence which match with the root words
        //brute force:
        /*
        match each root word with the words in the dictionary
        root word will always be the first in the words of the sentence
        
        */
        
        //TC=O(d*logd)+O(d*n)
        //SC=O(n)
//         sort(dictionary.begin(),dictionary.end());
        
//         stringstream ss(sentence);
        
//         vector<string> words;
//         string word;
//         while(ss>>word){
//             words.push_back(word);
//         }
        
//         int n=words.size();
//         for(int i=0;i<words.size();i++){
//             for(int j=0;j<dictionary.size();j++){
//                 bool matched=true;
//                 for(int k=0;k<dictionary[j].size();k++){
//                     if(dictionary[j][k]!=words[i][k]){
//                         matched=false;
//                         break;
//                     }
//                 }
//                 if(matched==true){
//                     words[i]=dictionary[j];
//                 }
//             }
//         }
        
//         string ans="";
        
//         for(int i=0;i<words.size()-1;i++){
//             ans+=words[i]+" ";
//         }
        
//         return ans+words[n-1];
        
        //optimized approach
        //use set to store the roots which can be checked in O(1)
        //use stringstream to access the words of the sentence
        //SC=O(l*max size of root word)
        //TC=O(n*l)+O(w*l*l)
        //n: number of words
        //l: number of roots
        //w: max length of the word
        
        stringstream ss(sentence);
        set<string> st;
        string ans="";
        
        for(auto root: dictionary){
            st.insert(root);
        }
        
        string word;
        while(ss>>word){
            ans+=findRoot(word,st)+" ";
        }
        
        ans.pop_back();
        
        return ans;
        
    }
};