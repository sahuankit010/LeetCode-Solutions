class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int t[n+1];
        memset(t, 0, sizeof(t));
        
        for(int i=2; i<n+1; i++){
            t[i] = min(cost[i-1]+t[i-1], cost[i-2]+t[i-2]);
        }
        
        return t[n];
    }
};