class Solution {
public:
    
    bool feasible(vector<int>& weights,int c, int days){
        int daysNeeded = 1, currentLoad = 0;
        
        for(int w: weights){
            currentLoad += w;
            
            if(currentLoad>c) {
                daysNeeded++;
                currentLoad = w;
            }
        }
        
        return daysNeeded<=days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = accumulate(begin(weights), end(weights), 0);
        int maxi = *max_element(begin(weights), end(weights));
        
        int l = maxi, r = sum;
        
        while(l<r){
            int m = (l+r)/2;
            
            if(feasible(weights, m, days)) r = m;
            else l = m + 1;
        }
        
        return l;
    }
};