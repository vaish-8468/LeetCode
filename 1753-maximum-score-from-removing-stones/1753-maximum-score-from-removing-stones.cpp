class Solution {
public:
    int maximumScore(int a, int b, int c) {
       
        int count = 0;
        priority_queue<int> pq;
        
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        while (pq.size() > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            
            count++;
            --x; --y;
            
            if (x > 0) pq.push(x);
            if (y > 0) pq.push(y);
        }
        
        return count;
        
    }
};