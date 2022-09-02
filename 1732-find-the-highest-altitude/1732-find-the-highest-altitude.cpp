class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = INT_MIN;
        int n=gain.size();
        int prefixSum=0;
        for(int i=0;i<n;i++){
            res = max(res, prefixSum);
            prefixSum+=gain[i];
            
        }
        res = max(res, prefixSum);
        return res;
    }
};