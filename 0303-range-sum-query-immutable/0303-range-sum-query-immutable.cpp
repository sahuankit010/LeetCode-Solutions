class NumArray {
public:
    vector<int> vec;
    NumArray(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(i!=0){
                int t = nums[i];
                int q = vec[i-1];
                vec.push_back(t+q);
            } else{
                vec.push_back(nums[i]);
            }
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return vec[right];
        return (vec[right]- vec[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */