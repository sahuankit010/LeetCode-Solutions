class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>ump;
        
        for(int i: nums) ump[i]++;
        
        int twice=-1, missing=-1;
        
        for(int i=1; i<=nums.size(); i++){
            if(ump[i]==0) missing = i;
            else if(ump[i]==2) twice = i;
         }
        
        return {twice, missing};
    }
};