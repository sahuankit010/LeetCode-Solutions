class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k1) {
        long long ans=0;
        int n = nums.size();
        long long k = k1;
        
        long long prefixSum = 0;
        unordered_map<long long,long long> mp;
        for(int i=0; i<n; i++){
            prefixSum += nums[i];
            
            if(prefixSum == k) ans = i+1;
            if(mp.find(prefixSum)==mp.end()){
                mp.insert({prefixSum, i});
            }
            if(mp.find(prefixSum-k) != mp.end()){
                ans = max(ans, i-mp[prefixSum-k]);
            }
            
        }
        
        return ans;
    }
};