class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size()<=2){
            return accumulate(cost.begin(), cost.end(), 0);
        }
        sort(cost.begin(), cost.end(), greater<int>());
        int n=cost.size();
        int ans = 0;
        int prev=-1;
        for(int i=0; i<n-2; i = i+3){
            ans += cost[i] + cost[i+1];
            prev = i+3;
        }
        
        for(int i=prev; i<n; i++){
            ans += cost[i];
        }
        return ans;
        
    }
};