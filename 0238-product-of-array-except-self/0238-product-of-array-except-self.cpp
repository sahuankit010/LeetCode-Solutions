class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefix(n), suffix(n);

        prefix[0] = 1;
        suffix[n-1] = 1;

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for(int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        vector<int> ans(n);

        for(int i=0; i<n; i++){
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
        
        // int countZero = 0;
        
        // for(int i: nums) {
        //     // product *= i;
        //     if(i == 0) countZero++;
        // }

        // int n = nums.size();
        
        // vector<int> ans(n);

        // if(countZero >= 2){
        //     fill(begin(ans), end(ans), 0);
        //     return ans;
        // }
            

        // int product = 1;

        // if(countZero == 1){
        //     for(int i = 0; i<n; i++){
        //         if(nums[i] != 0) product *= nums[i];
        //     }

        //     for(int i=0; i<n; i++){
        //         if(nums[i] != 0) ans[i] = 0;
        //         else ans[i] = product;
        //     }

        //     return ans;
        // }

        // for(int i = 0; i<n; i++){
        //     product *= nums[i];
        // }

        // for(int i=0; i<n; i++){
        //     ans[i] = product/nums[i];
        // }

        // return ans;
    }
};