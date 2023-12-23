class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        st.insert({0,0});
        int x=0,y=0;
        bool ans=false;
        
        for(int i=0;i<path.length();i++){
            if(path[i]=='N'){
                y=y-4;
            }
            else if(path[i]=='S'){
                y=y+4;
            }
            else if(path[i]=='E'){
                x=x+4;
            }
            else if(path[i]=='W'){
                x=x-4;
            }
            
            if(st.count({x,y})!=0){
                ans=true;
                break;
            }
            st.insert({x,y});
        }
        
        return ans;
    }
};