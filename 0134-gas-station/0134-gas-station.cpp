class Solution {
public:
   int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;//kitna petrol kam hai 
        int balance = 0;// kitna petrol bachha hai
        int start = 0; // kaha se start karna hai 

        for(int i = 0 ; i < gas.size(); i++){
            balance += gas[i] - cost[i];// if balance value is negative 
            cout <<" bal: " << balance <<" ";
            if(balance < 0){// balance value is negative then
                deficit += balance;//got mistake here 
                start = i+1;
                balance = 0;
            }
             cout << " deficit: " << deficit <<" ";
        }
        //if not get negative
        if(balance + deficit >= 0){
            return start;
        }else{
            return -1;
        }
    }
};