class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans = 0;
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            
            
            for(int j=0; j<n; j++){
                if(i==j) continue;
                string temp = "";
                temp += nums[i] + nums[j];
                if(temp == target) ans++;
            }
        }
        
        return ans;
    }
};