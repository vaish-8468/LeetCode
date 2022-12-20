
class Solution {
public:
    
     vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int N = A.size();
        int j = lower_bound(A.begin(), A.end(), x) - A.begin();
        int i = j - 1;
        
        while (j - i - 1 < k) {
            if (i == -1 || (j < N && abs(A[j] - x) < abs(A[i] - x))) j++;
            else i--;
        }
        
        return vector<int>(A.begin() + i + 1, A.begin() + j);
    }


};