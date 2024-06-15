class Solution {
public:
//     int K;
//     int N;
//     int helperFunc(int index, int k,int w, vector<int>& profits, vector<int>& capital){
//         //base case
//         if(k==0){
//             return w;
//         }
//         if(index==N){
//             if(k==0){
//                 return w;
//             }
//             else{
//                 return 0;
//             }
//         }
        
//         int take=0;
        
//         if(capital[index]>=w){
//             take=helperFunc(index+1,k-1,w+profits[index],profits,capital);
//         }
//         int not_take=helperFunc(index+1,k,w,profits,capital);
        
//         int maxi=max(take,not_take);
        
//         return maxi;
//     }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //redo############
        // K=k;
        // N=profits.size();
        // return helperFunc(0,k,w,profits,capital);
        int n=profits.size();
        
        vector<pair<int,int>> vec;
        
        priority_queue<int> pq; //by default max-heap
        
        for(int i=0;i<n;i++){
            vec.push_back({capital[i],profits[i]});
        }
        
        sort(vec.begin(),vec.end()); //sort wrt to capital
        int i=0;
        while(k--){
            while(i<n && vec[i].first<=w){
                pq.push(vec[i].second); //push all the profits whose capital is less than or equal to w
                i++;
            }
            
            if(pq.empty()){
                break;
            }
            
            w+=pq.top(); //take the profit and pop it from the queue
            pq.pop();
        }
        
        return w;
    }
};