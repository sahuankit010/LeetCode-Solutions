class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        vector<int> vec(s.begin(),s.end());
        sort(vec.begin(), vec.end(), greater<int>());
        if(vec.size()>=3) return vec[2];
        if(vec.size()>=2) return vec[0];
        return vec[0];
    }
};