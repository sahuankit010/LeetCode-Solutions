class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0, res=0;
        int r = nums.size()-1;
        while(l<r){
            if(nums[l]==val){
                swap(nums[l],nums[r]);
            }
            if(nums[l]!=val){
                l++;
            }
            if(nums[r]==val) r--;
        }
        
        for(int i = 0; i<nums.size();i++){
            if(nums[i]!=val){
                res++;
            }
        }
        
        return res;
    }
};