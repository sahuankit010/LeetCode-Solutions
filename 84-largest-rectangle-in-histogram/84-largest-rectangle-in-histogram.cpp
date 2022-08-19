class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int curr = 0, res = 0;
        int tp;
        int n = heights.size();
        
        for(int i=0;i<n;i++){
            
            while(!s.empty()&& heights[s.top()]>=heights[i]){
                
                tp = s.top();
                s.pop();
                
                curr = heights[tp]* (s.empty()? i : i - s.top() - 1);
                res=max(res,curr);
            }
            
            s.push(i);
        }
        
        while(!s.empty()){
            tp = s.top();
            s.pop();    
            curr = heights[tp]* (s.empty()? n: n - s.top() - 1);
            res=max(res,curr);
        }
        return res;
    }
};