class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int ans = 10000000;
        
        for(int i=0;i<nums.size()-2;i++){
            
            int left = i+1, right = nums.size()-1;
            
            while(left<right){
                
             int curr_sum = nums[i]+nums[left]+nums[right];
                
                if(curr_sum==target) return curr_sum;
                
                if(abs(target-curr_sum)<abs(target-ans)){
                    ans = curr_sum;
                }
                if(curr_sum<target) left++;
                else right--;
            }
        }
        return ans;
    }
};