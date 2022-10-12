class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n=nums.size();
        long long per = INT_MIN;
        long long curr = INT_MIN;
        for(int i=0; i<=n-3; i++){
            int a = nums[i];
            int b=nums[i+1];
            int c=nums[i+2];
            
            if(a+b>c and b+c>a and c+a>b){
                curr = a+b+c;
                per = max(per, curr);
            }
            
            
        }
        
        return per==INT_MIN?0: per;
    }
};