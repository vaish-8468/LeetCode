class Solution {
public:
    
    
    int numTeams(vector<int>& rating) {
        int count=0;
        int n=rating.size();
        //i<j<k always
        for(int j=1;j<n-1;j++){
            int leftSmaller=0;
            int leftLarger=0;
            int rightSmaller=0;
            int rightLarger=0;
            
            //count number of smaller and larger elements to the left of rating[j]
            for(int i=0;i<j;i++){
                if(rating[i]<rating[j]){
                    leftSmaller++;
                }
                else if(rating[i]>rating[j]){
                    leftLarger++;
                }
            }
            
            //count number of smaller andb larger elements to the right of rating[j]
            for(int k=j+1;k<n;k++){
                if(rating[j]<rating[k]){
                    rightLarger++;
                }
                else if(rating[j]>rating[k]){
                    rightSmaller++;
                }
            }
            
            count+=(leftLarger*rightSmaller)+(leftSmaller*rightLarger);
        }
         
            

        return count;
    }
};