class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        int n=nums.size();
        for(int i=0; i<n-2; i++){
            // int curr1 = ;
            for(int j=i+1; j<n-1; j++){
                int curr1 = nums[j]-nums[i];
                for(int k=j+1; k<n; k++){
                    int curr2 = nums[k]-nums[j];
                    if(curr1 == curr2 && curr1 == diff) count++; 
                }
            }
        }
        return count;
    }
};