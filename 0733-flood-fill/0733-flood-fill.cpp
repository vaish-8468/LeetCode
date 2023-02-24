class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        
        vector<vector<int>> visited(m, vector<int> (n, 0));
        queue<pair<int,int>> q;
        vector<vector<int>> modified=image;
        int val=image[sr][sc];
        if(val==color){
            return image;
        }
        else{
            modified[sr][sc]=color;
        }
        q.push({sr,sc});
        visited[sr][sc]=1;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!q.empty()){
            int cell_r=q.front().first;
            int cell_c=q.front().second;
            q.pop();
    
     
            if(image[cell_r][cell_c]==val && visited[cell_r][cell_c]!=1){
                visited[cell_r][cell_c]=1;
                modified[cell_r][cell_c]=color;
            }
            for(int i=0;i<4;i++){
                int nrow=(cell_r)+row[i];
                int ncol=(cell_c)+col[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==val && visited[nrow][ncol]!=1){
                q.push({nrow,ncol});
                visited[nrow][ncol]=1;
                modified[nrow][ncol]=color;
            }
            }
        }
        
        return modified;
            }
            
            
        

            
            

    
};