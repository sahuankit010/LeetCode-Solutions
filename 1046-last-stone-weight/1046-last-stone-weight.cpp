class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        
        for(auto x: stones) pq.push(x);
        
        while(pq.size()>=1){
            if(pq.size()==1) break;
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            
            if(x!=y){
                pq.push(abs(x-y));
            }
        }
        
        return pq.empty()? 0: pq.top();
    }
};