class Solution {
public:
    string getPermutation(int n, int k) {
        string answer="";
        vector<int> num;
        int f=1;
        for(int i=1;i<n;i++){
            f=f*i;
            num.push_back(i);
        }
        num.push_back(n);
        k-=1;
        while(k>-1){
            answer+=to_string(num[k/f]);
            num.erase(num.begin()+k/f);
            if(num.size()==0){
                break;
            }
            k=k%f;
            f=f/num.size();
        }
        return answer;
    }
};