class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>ump;
        
        for(int i=0;i<nums.size();i++){
            ump[nums[i]]++;
        }
        
        for(auto x:ump){
            if(x.second>floor(nums.size()/3)){
                ans.push_back(x.first);
            }
        }
        
        return ans;
    }
};