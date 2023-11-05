class Solution {
public:
    //BRUTE FORCE
    string count(int n){
        if(n==1){
            return "1";
        }
        string str=count(n-1);
        // cout<<str<<"->"<<n<<endl;
        //initializing the count for first char of str
        int cnt=1;
        string temp; //transformed string
        for(int i=1;i<str.length();i++){
            //if previous char does not matches curr
            //add it's frequency and char in the string and reset the count to 1 
            //for the curr char
            if(str[i-1]!=str[i]){
                temp+=to_string(cnt)+str[i-1];
                cnt=1;
            }
            else{
                //otherwise count the frequency
                cnt++;
            }
        }
        //if the loop ends
        //add the frequency of the last char of the string
        temp+=to_string(cnt)+str[str.length()-1];
        // cout<<temp<<endl;
        
        
        return temp;
        
    }
    string countAndSay(int n) {
        string ans=count(n);
        
        return ans;
        
    }
};