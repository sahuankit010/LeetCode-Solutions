class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(!nums.size()) return 0;
        int ans=0, n= nums.size();
        int k=1;
        int left = 0, zero=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) zero++;
            
            while(left<=i && zero>k){
                if(nums[left]==0) zero--;
                left++;
            }
            ans = max(ans,i-left+1);
        }
        
        return ans;
    }
};