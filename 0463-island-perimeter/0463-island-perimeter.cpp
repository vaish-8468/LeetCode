class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        //count only those blocks which has water atleast on one of its side.
        int dx[4]={0,-1,0,1};
        int dy[4]={-1,0,1,0};
        int m=grid.size();
        int n=grid[0].size();
        int perimeter=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int x=i+dx[k];
                        int y=j+dy[k];
                        if(x>-1 && x<m && y>-1 && y<n){
                            //if the range is within the grid
                            //consider only those sides of the block which has water
                            if(grid[x][y]==0){
                                perimeter+=1;
                            }
                        }
                        else{
                            //otherwise it will be all water around
                            //hence consider its side for sure
                            perimeter+=1;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};