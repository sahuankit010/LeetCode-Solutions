class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        set<int>s(nums.begin(),nums.end());
        vector<int>vec(s.begin(),s.end());
        int res = -1;
        int curr = 1;
        for(int i=1;i<vec.size();i++){
          
          if(vec[i-1]==vec[i]-1) curr++;
          else{
              res=max(res,curr);
              curr=1;
          }
        }
        return max(curr,res);
    }
};