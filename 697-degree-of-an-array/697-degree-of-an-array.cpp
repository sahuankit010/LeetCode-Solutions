class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // unordered_map<int,int>mp;
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        int maxSize=INT_MIN;
        
        
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            int size = mp[nums[i]].size();
            maxSize=max(maxSize,size);
        }
        int ans=INT_MAX;
        for(auto it:mp){
            
            if(it.second.size()==maxSize){
                int len = it.second[it.second.size()-1]-it.second[0]+1;
                ans=min(ans,len);
            }
        }
        return ans;
    }
};