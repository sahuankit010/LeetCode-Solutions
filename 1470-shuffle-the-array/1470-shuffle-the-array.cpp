class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        for(int i=n; i<nums.size(); i++){
            int second = nums[i]<<10;
            nums[i-n] |= second;
        }
        int allOne = pow(2,10)-1;
        
        for(int i=n-1; i>=0; i--){
            int second = nums[i] >> 10;
            int first = nums[i] & allOne;
            
            nums[(2*i) + 1] = second;
            nums[2*i]  = first;
        }
        return nums;
    }
};