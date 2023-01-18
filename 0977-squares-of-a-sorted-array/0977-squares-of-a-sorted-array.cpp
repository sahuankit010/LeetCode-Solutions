class Solution {
public:
    vector<int> negatives(vector<int> nums, int n){
        vector<int> ans;
        for(int i = n-1; i>=0; i--){
            ans.push_back(nums[i]*nums[i]);
        }
        return ans;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        
        int idx = -1, n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>=0) {
                idx = i;
                break;
            }
        }
        if(idx == -1){
            return negatives(nums, n);
        }
        
        int i=idx-1;;
        vector<int> ans;
        
        while(i>=0 && idx<n){
            if((nums[idx]*nums[idx])<=(nums[i]*nums[i])){
                ans.push_back(nums[idx]*nums[idx]);
                idx++;
            } else{
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
        }
        if(i<0){
            for(int j=idx; j<n; j++)
                ans.push_back(nums[j]*nums[j]);
        }else{
            for(int j=i; j>=0; j--)
                ans.push_back(nums[j]*nums[j]);
        }
        return ans;
    }
};