class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         unordered_map<int,bool> mp;
        
        for(int i =0;i<nums.size();i++){
            if(nums[i]>0){
                mp[nums[i]]=true;
            }
        }
        
        for(int i =1;i<=1000000;i++){
            if(!mp[i]) return i;
        }
        
        return -2;
    }
};