class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return false;
        // cout<<n<<endl;
        
        // for(int i=0; i<n-1; i++){
        //     if(nums[i]>nums[i+1])
        //         return i;
        // }
        // return -1;

        int l=0, h=n-1;
        
        while(l<=h){
            int mid = l + (h-l)/2;
            int curr = nums[mid];
            if(curr>nums[mid-1] && curr>nums[mid+1]) return mid;
            else if(curr>nums[mid-1] && curr<nums[mid+1]) l=mid;
            else h=mid;
        }
        
        return INT_MAX;
    }
};