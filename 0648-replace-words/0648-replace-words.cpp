class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        //find the words from the sentence which match with the root words
        //brute force:
        /*
        match each root word with the words in the dictionary
        root word will always be the first in the words of the sentence
        
        */
        sort(dictionary.begin(),dictionary.end());
        
        stringstream ss(sentence);
        
        vector<string> words;
        string word;
        while(ss>>word){
            words.push_back(word);
        }
        
        int n=words.size();
        for(int i=0;i<words.size();i++){
            for(int j=0;j<dictionary.size();j++){
                bool matched=true;
                for(int k=0;k<dictionary[j].size();k++){
                    if(dictionary[j][k]!=words[i][k]){
                        matched=false;
                        break;
                    }
                }
                if(matched==true){
                    words[i]=dictionary[j];
                }
            }
        }
        
        string ans="";
        
        for(int i=0;i<words.size()-1;i++){
            ans+=words[i]+" ";
        }
        
        return ans+words[n-1];
        
    }
};