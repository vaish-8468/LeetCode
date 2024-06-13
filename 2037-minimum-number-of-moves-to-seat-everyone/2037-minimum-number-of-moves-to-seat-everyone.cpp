class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // unordered_set<pair<int,int>> st;
        int n=seats.size();
        int moves=0;
        //mark the taken seats to -1
        
        sort(seats.begin(),seats.end());
        
        sort(students.begin(),students.end());
        //TC=O(nlogn)
        
        for(int i=0;i<n;i++){
            moves+=abs(seats[i]-students[i]);

        }
        
        return moves;
    }
    
};