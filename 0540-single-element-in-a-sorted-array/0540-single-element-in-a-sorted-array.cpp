class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        unordered_map<int,int> ump;
        
        for(int i=0; i<n; i++){
            ump[nums[i]]++;
        }
        for(auto x: ump){
            if(x.second == 1) return x.first;
        }
        return -1;
    }
};