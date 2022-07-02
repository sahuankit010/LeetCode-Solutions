class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>ump;
        
        ump.insert({nums[0],1});
        
        for(int i=1;i<nums.size();i++){
            if(ump.find(nums[i])!=ump.end()){
                return true;
            } else{
                ump[nums[i]];
            }
        }
        
        return false;
    }
};