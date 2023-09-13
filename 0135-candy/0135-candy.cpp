class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int res=0;
        
        vector<int> candies(n,1); //initially every child will have atleast 1 candy
        
        //for every child, check it's neighbour
        

        
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                //store the maximum candy that can be collected if ith rating is greater than i-1th rating
                candies[i]=max(candies[i], candies[i-1]+1);
                 
            }
          
        }
        
        for(int i=n-2;i>=0;i--){
            //traverse from right to left,
            //again, collect the maximum possible candy for each ith rating greater than i+1th rating
            if(ratings[i]>ratings[i+1]){
                candies[i]=max(candies[i], candies[i+1]+1);
            }
           
        }
        
        //logic used is, total min candies will sum of maximum possible candies for each child
        
        //calculate total candies collected
        for(int i=0;i<n;i++){
            res+=candies[i];
        }
        
        return res;
    }
};