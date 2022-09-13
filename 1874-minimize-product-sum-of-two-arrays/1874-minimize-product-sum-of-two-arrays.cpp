class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
    
        priority_queue<int> pq;      
        for (int num : nums2)
            pq.push(num);
        
        int ans = 0;

        for (int i = 0; i < nums2.size(); ++i) {
            ans += nums1[i] * pq.top();
            pq.pop();
        }
        
        return ans;   
    }
};