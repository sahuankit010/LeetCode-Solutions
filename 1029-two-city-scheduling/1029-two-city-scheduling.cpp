class Solution {
public:
    
    static bool com(vector<int> &a,vector<int> &b){
        return a[1]-a[0]> b[1]-b[0];
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), com);
        int n=costs.size();
        int ans=0;
        for(int i=0; i<n; i++){
            ans += i<n/2? costs[i][0]: costs[i][1];
        }
        
        return ans;
    }

};