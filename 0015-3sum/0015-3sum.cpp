class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        int n=nums.size();
        
        for(int i = 0; i < n &&  nums[i] <= 0; i++){
            
            if(i==0 || nums[i-1]!=nums[i]){
                int l = i+1, r = n-1;
            
                while(l<r){
                    int sum = nums[i] + nums[l] + nums[r];
                
                    if(sum>0) r--;
                    else if(sum<0) l++;
                    else{
                        ans.push_back({nums[l++], nums[i], nums[r--]});
                        while(l<r && nums[l] ==  nums[l-1]) l++;
                    }
                }
            }
        }
        return ans;
    }
};