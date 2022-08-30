class Solution {
public:
     void rotate(vector<int> &nums, int l, int r){
        while(l < r)    
            swap(nums[l++], nums[r--]);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        rotate(nums, 0, n-k-1);
        rotate(nums, n-k, n-1);
        rotate(nums, 0, n-1);
        
    }
    
};