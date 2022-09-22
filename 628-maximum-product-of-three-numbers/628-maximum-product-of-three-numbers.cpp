class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>>pq;//min heap
        priority_queue<int>pq1;// max heap
        int  maxi = INT_MIN;
        for(int i=0;i<3; i++){
            maxi = max(maxi, nums[i]);
            pq.push(nums[i]);
        }
        for(int i=0;i<2; i++){
            pq1.push(nums[i]);
        }
        int n = nums.size();
        for(int i=3; i<n; i++){
            maxi = max(maxi, nums[i]);
            if(nums[i]>pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        for(int i=2; i<n; i++){
            if(nums[i]<pq1.top()) {
                pq1.pop();
                pq1.push(nums[i]);
            }
        }
        
        int ans = 1;
        // int  maxi = pq.top();x
        int ans1 = 1;
        
        while(!pq1.empty()){
            ans1 *= pq1.top();
            pq1.pop();
        }
        while(!pq.empty()){
            ans *= pq.top();
            pq.pop();
        }
        
        return max(ans, ans1*maxi); 
    }
};