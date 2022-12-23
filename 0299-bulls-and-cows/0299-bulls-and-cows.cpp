class Solution {
public:
    string getHint(string secret, string guess) {
        
        unordered_map<char,int> sp;
        int bulls=0;
        int cows=0;
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                if(sp.find(secret[i])!=sp.end()){
                sp[secret[i]]++;
            }
            else{
                sp[secret[i]]=1;
            }
            }
        }
        for(int i=0;i<guess.length();i++){
            if(secret[i]!=guess[i])
            {
            if(sp.find(guess[i])!=sp.end()){
                cows++;
                if(sp[guess[i]]==1){
                    sp.erase(guess[i]);
                }
                else{
                    sp[guess[i]]--;
                }
                
            }
           
            }
            
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
       
        
        
    }
};