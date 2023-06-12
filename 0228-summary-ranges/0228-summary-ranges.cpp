class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        for(int i=0; i<n;){
            int j = i;
            
            while(j<n-1 && nums[j]+1 == nums[j+1])
                j++;
            
            if(i!=j){
                ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
                i=j+1;
            } else{
                ans.push_back(to_string(nums[i]));
                i++;
            }
        }
        
        return ans;
    }
};