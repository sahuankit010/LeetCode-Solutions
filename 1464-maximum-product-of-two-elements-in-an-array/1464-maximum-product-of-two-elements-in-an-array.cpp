class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0;i<2; i++){
            pq.push(nums[i]);
        }
        int n = nums.size();
        for(int i=2; i<n; i++){
            if(nums[i]>pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        int ans = 1;
        
        while(!pq.empty()){
            ans *= pq.top()-1;
            pq.pop();
        }
        return ans;
    }
};