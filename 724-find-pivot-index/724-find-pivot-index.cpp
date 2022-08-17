class Solution {
public:
    int pivotIndex(vector<int>& nums) {
          
        int leftsum = 0, rightsum = 0;
        int i = 1;
        for(i = 1; i < nums.size(); i++)
            rightsum += nums[i];
        for(i = 0; i < nums.size()-1; i++){
            // cout<<leftsum<<" "<<rightsum<<endl;
            if(leftsum == rightsum) return i;
            leftsum += nums[i];;
            rightsum -= nums[i+1];
        }
        // cout<<leftsum<<" "<<rightsum<<endl;
        if(leftsum==0)return i;
            return -1;
    }
};