class Solution {
public:
    string getHint(string secret, string guess) {
        
        unordered_map<char,int> sp;
        int bulls=0;
        int cows=0;
        for(int i=0;i<secret.length();i++){
            //for secret string
            if(secret[i]==guess[i]){
                bulls++;
                //increases the bull count if digits are at their correct place
            }
            else{
                //otherwise keep a record of frequency of digits which are at their incorrect position
                if(sp.find(secret[i])!=sp.end()){
                sp[secret[i]]++;
            }
            else{
                sp[secret[i]]=1;
            }
                
        }
      }
        for(int i=0;i<guess.length();i++){
            //for guess string
            if(secret[i]!=guess[i])
                //if unequal digits are found at a particular position
            {
            if(sp.find(guess[i])!=sp.end()){
                cows++;
                //if they already exist in the map, we simply remove them if the frequency is 1 otherwise we decrease the frequency
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