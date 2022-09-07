class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0, r = nums.size()-1;
        
        while(l<r){
            if(nums[r]%2==0){
                swap(nums[l], nums[r]);
                    l++;
            }else{
                r--;
            }
        }
        return nums;
    }
};