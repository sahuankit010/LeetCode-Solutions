class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int zero=0, mul=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero++;
            else mul*=nums[i];
        }
        vector<int>ans;
        if(zero>=2){
            for(int i=0;i<nums.size();i++){
                ans.push_back(0);
            }
        }
        
        else if(zero==1){
             for(int i=0;i<nums.size();i++){
                if(nums[i]==0) ans.push_back(mul);
                 else ans.push_back(0);
            }
            
        }
        
        else{
                for(int i = 0;i<nums.size();i++){
                    ans.push_back(mul/nums[i]);
            }
        }
        
        return ans;
    }
};