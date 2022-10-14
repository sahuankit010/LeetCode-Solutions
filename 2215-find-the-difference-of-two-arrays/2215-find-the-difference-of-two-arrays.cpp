class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        ans.push_back({});
        ans.push_back({});
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        unordered_map<int,int>mp1, mp2;
        int m=nums1.size(), n=nums2.size();
        for(int i=0;i<m; i++) mp1[nums1[i]]++;
        for(int i=0; i<n; i++) mp2[nums2[i]]++;
        int k=0;
        for(int i=0;i<m; i++){
            if(mp2.find(nums1[i])==mp2.end()){
                if(ans[0].size()==0){
                    ans[0].push_back(nums1[i]);
                    k++;
                }
                if(ans[0].size()>=1 && ans[0][k-1]!=nums1[i]) {
                    ans[0].push_back(nums1[i]);
                    k++;
                }
            } 
        }
        k=0;
        for(int i=0;i<n; i++){
            // if(mp1.find(nums2[i])==mp1.end()) ans[1].push_back(nums2[i]);
            if(mp1.find(nums2[i])==mp1.end()){
                if(ans[1].size()==0){
                    ans[1].push_back(nums2[i]);
                    k++;
                }
                if(ans[1].size()>=1 && ans[1][k-1]!=nums2[i]) {
                    ans[1].push_back(nums2[i]);
                    k++;
                }
            } 
        }
        return ans;
    }
};