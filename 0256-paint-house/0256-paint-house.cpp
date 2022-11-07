class Solution {
public:
    
    // int min3(int a, int b, int c){
    //     if(a<=b and a<=c) return a;
    //     else if(b<a and b<=c) return b;
    //     else return c;
    // }
    int minCost(vector<vector<int>>& costs) {
        int n=costs.size();
        if(n==1){
            return min(costs[0][0], min(costs[0][1],costs[0][2]));
        }
        
        for(int i=1; i<n; i++){
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][2], costs[i-1][0]);
            costs[i][2] += min(costs[i-1][1], costs[i-1][0]);
        }
        
        return min(costs[n-1][0], min(costs[n-1][1], costs[n-1][2]));
    }
};