#define ll long long
/*
Time Complexity -> O(n cube)
Space: O(1)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                ll rem = (ll)target - (ll)nums[i] - (ll)nums[j];

                int low = j + 1, high = n - 1;

                while (low < high) {

                    if (nums[low] + nums[high] == rem) {
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        // int tempIndex1 = low, tempIndex2 = high;
                        low++;
                        high--;
                        while(low < high && nums[low-1] == nums[low]) low++;
                        while(low < high && nums[high+1] == nums[high]) high--;

                    } else if (nums[low] + nums[high] < rem) {
                        low++;
                    } else
                        high--;
                }

                while(j+1<n && nums[j] == nums[j+1]) j++;
            }
            while(i+1<n && nums[i] == nums[i+1]) i++;
        }


        return ans;
    }
};