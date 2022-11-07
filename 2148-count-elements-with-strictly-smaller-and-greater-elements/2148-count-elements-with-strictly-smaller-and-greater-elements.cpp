class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n=nums.size();
        for(int i=1; i<n; i++){
            int j=i-1;
            while(j>=0 && nums[j]>=nums[i]){
                j--;
            }
            int k=i+1;
            while(k<n && nums[k]<=nums[i]){
               k++;
            }
            cout<<j<<" "<<k<<endl;
            if(j>=0 && k<n) ans++;
        }
        
        return ans;
    }
};