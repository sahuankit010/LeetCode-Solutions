class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int rightMax[n], leftMin[n];
        rightMax[n-1]= prices[n-1];
        
        for(int i=n-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1], prices[i]);
        }
        
        leftMin[0] = prices[0];
        
        for(int i=1; i<n;i++){
            leftMin[i] = min(leftMin[i-1], prices[i]);
        }
        
        for(int i=0;i<n;i++){
            ans = max(ans, rightMax[i]-leftMin[i]);
        }
        
        return ans;
    }
};