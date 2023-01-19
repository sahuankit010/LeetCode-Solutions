class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ump;
        for(int i: nums1){
            ump[i]++;
        }
        vector<int> ans;
        for(int i=0; i<nums2.size(); i++){
            if(ump.find(nums2[i])!=ump.end()){
                if(ump[nums2[i]]>1){
                    ump[nums2[i]]--;
                } else {
                    ump.erase(nums2[i]);
                }
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};