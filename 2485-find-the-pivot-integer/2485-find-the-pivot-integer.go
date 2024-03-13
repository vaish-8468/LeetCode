func pivotInteger(n int) int {
    if(n==1){
        return 1;
    }
    var sumEnd int= n*(n+1)/2;
    var sumStart int=0;
    var ans int=-1;
    
    for i:=0;i<n;i++ {
        if(sumEnd==sumStart+i){
            ans=i;
        }
        
        sumEnd-=i;
        sumStart+=i;
    }
    
    return ans;
}