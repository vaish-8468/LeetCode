class Solution {
public:
    int drows[4]={1,0,0,-1};
    int dcols[4]={0,-1,1,0};
    
    
    bool checkCell(int row, int col, int mid, vector<vector<int>>& cells){
        vector<vector<bool>> visited(row,vector<bool>(col,false));  //to keep a record of the path from top row to bottom row considering all is land
        
        //mark all the cells till mid as water
        for(int c=0;c<mid;c++){
            visited[cells[c][0]-1][cells[c][1]-1]=true; //marked as water
        }
        
        //BFS traversal
        queue<pair<int,int>> q; //storing rows and cols
        
        //push all the top row cells which are not water of them will behave as a source cell
        
        for(int i=0;i<col;i++){
            if(visited[0][i]==0){
                visited[0][i]=true;//mark it as visited
                q.push({0,i});
            }
        }
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            if(x==row-1){
                return true; //if bottom row cell is reached that means path exists
            }
            
            for(int l=0;l<4;l++){
                int nrow=x+drows[l];
                int ncol=y+dcols[l];
                
                
                if(nrow<0 || ncol<0 || nrow==row || ncol==col || visited[nrow][ncol]==true){
                    continue; //if index is out of range or cell has alraedy been visited
                }
                
                //otherwise
                visited[nrow][ncol]=true;
                q.push({nrow,ncol});
                    
                }  
        }
        
        return false; //path not possible
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int size=cells.size();
        int ans=0;
        
        int left=1;
        int right=size;
        
        while(left<=right){ //binary search
            int mid=left+ (right-left)/2;
            if(checkCell(row,col,mid,cells)){
                ans=mid; //max cell index upto which path is possible
                left=mid+1; //increasing the range
            }
            else{
                right=mid-1;
            }
        }
        
        return ans;
       
        
    }
};