class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        // sort(nums1,nums1+nums1.size());
        // sort(nums2,nums2+nums2.size());
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>ans;
        int i = 0, j=0, n1= nums1.size(), n2 = nums2.size();
        while(i<n1 and j<n2){
            if( nums1[i]==nums2[j] and mp.find(nums1[i])==mp.end()){
                
                ans.push_back(nums1[i]);
                mp[nums1[i]]++;
                i++;
                j++;
                // if(mp.find(nums1[i])==mp.end()){
                //     ans.push_back(nums1[i++]);
                //     j++;
                // }
                // else if(mp.find(nums2[j])==mp.end()){
                //     ans.push_back(nums2[j++]);i++;
                // }
            } else if(nums1[i]<nums2[j]){
                i++;
            } else{
                j++;
            }
        }
        return ans;
    }
};