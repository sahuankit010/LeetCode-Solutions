class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)nums[i]=-1;
        }
        
        int sum=0;
        int max_len = 0; // Initialize result
        int ending_index = -1;
        unordered_map<int,int>hM;
        for (int i = 0; i < nums.size(); i++) {
        
        sum += nums[i];
 
 
        if (sum == 0) {
            max_len = i + 1;
            ending_index = i;
        }
 
        if (hM.find(sum) != hM.end()) {
            
            if (max_len < i - hM[sum]) {
                max_len = i - hM[sum];
                ending_index = i;
            }
        }
        else
            hM[sum] = i;
        }
        return max_len;
    }
};