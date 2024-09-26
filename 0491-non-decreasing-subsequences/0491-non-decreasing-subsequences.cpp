class Solution {
public:
    int n;

    void backtrack(vector<int>& nums, int idx, vector<int> &curr, vector<vector<int>> &ans){
        if(curr.size()>=2){
            ans.push_back(curr);
        }

        unordered_set<int> set;

        for(int i=idx; i<n; i++){
            if((curr.empty() || curr.back()<=nums[i]) && !set.count(nums[i])){
                curr.push_back(nums[i]);
                backtrack(nums, i+1, curr, ans);
                curr.pop_back();
                set.insert(nums[i]);
            }
        }

    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;

        backtrack(nums, 0, curr, ans);

        return ans;
    }
};