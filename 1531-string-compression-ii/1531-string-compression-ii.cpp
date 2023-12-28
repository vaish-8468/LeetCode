int arr[101][27][101][101]; //stored in heap


class Solution {
public: 
    int n;
    string S;
    int optimalLengthEncoded(int idx, int prevChar, int freq, int k){
        if(k<0){
            return INT_MAX;
        }
        if(idx>=n){
            return 0;
        }
        
        if(arr[idx][prevChar][freq][k] != -1){
            return arr[idx][prevChar][freq][k];
        }
        
        int delete_idx=optimalLengthEncoded(idx+1,prevChar,freq,k-1); //deleted
        //prevChar remains same
        int keep_idx=0;
        if(S[idx]-'a'!=prevChar){
            keep_idx=1+optimalLengthEncoded(idx+1,S[idx]-'a',1,k);
            //first occurence, hence, frequency is 1
            //prevChar changed and updated to current
        }

        else if(S[idx]-'a'== prevChar){
            int length_increased_by_one=0; //no addition of any character
            if(freq==1 || freq==9 || freq==99){
                length_increased_by_one=1;
            }
                    keep_idx=length_increased_by_one+optimalLengthEncoded(idx+1,prevChar,freq+1,k); //kept
            //prevChar remains same
        }
        
        return arr[idx][prevChar][freq][k]=min(keep_idx,delete_idx);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        n=s.length();
        S=s;
        memset(arr,-1,sizeof(arr));
        return optimalLengthEncoded(0,26,0,k);
    }
};