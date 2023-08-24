class Solution {
public:
    
    string GenerateLine(int i, int j, int evenSpaces, int extraSpaces, int maxWidth, vector<string>& words){
        string eachLine="";
        
        for(int k=i;k<j;k++){
            eachLine+=words[k];
            
            if(k==j-1){
                //add no space after last word
                continue;
            }
            
            for(int space=1;space<=evenSpaces;space++){
                eachLine+=" "; //add evenSpaces after each word
            }
            
            //now after adding even spaces, if there is any extraSpace left then add it also in order to justify the words towards left
            
            if(extraSpaces>0){
                eachLine+=" ";
                extraSpaces--;
            }
        }
            //after adding all the desired words, evenspaces, and extra spaces , if the line len is still less than maxWidth, add spaces till the limit
            
            while(eachLine.length()<maxWidth){
                eachLine+=" ";
            }
        
        return eachLine;
        
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        
//         int extraSpaces;
//         int evenSpaces;
        vector<string> ans;
        int i=0;
        while(i<n){
            int charCount=words[i].length();
            int totalSpaces=0; //total spaces before adding a  new word
            int j=i+1;
            while(j<n && words[j].length()+1+totalSpaces+charCount<=maxWidth){
                charCount+=words[j].length();
                totalSpaces+=1;
                
                j++;
                
            }
            
            //now when no more word could be added in the line
            //check for the remaining spaces
            
            int leftSpaces=maxWidth-charCount;
            
            //now divide these left spaces evenly among the totalSpaces required between and after every word
            
             int evenSpaces= (totalSpaces==0) ? 0:leftSpaces/totalSpaces;
            
            //extra spaces which are left even after evenly dividing the spaces/
             int extraSpaces= (totalSpaces==0) ? 0:leftSpaces%totalSpaces;
            
            //if it is the last word, then no need to evenly distribute spaces, just count one space after the word with no             extra space 
            if(j==n){
                evenSpaces=1;
                extraSpaces=0;
                //for last line
            }
            
            ans.push_back(GenerateLine(i,j,evenSpaces,extraSpaces,maxWidth,words));
            i=j; //start for the next line
        }
        return ans;
    }
};