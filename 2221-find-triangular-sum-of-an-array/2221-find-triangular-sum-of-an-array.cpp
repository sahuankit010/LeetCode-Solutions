class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        while(1){
            int s = nums.size();
            vector<int>tt;
            for(int i=0; i<s-1; i++){
                int t = nums[i]+nums[i+1];
                t=t%10;
                tt.push_back(t);
            }
            nums.clear();
            n=tt.size();
            if(n==1) return tt[0];
            for(int i=0; i<n; i++) 
                nums.push_back(tt[i]);
        }
        return -1;
    }
};