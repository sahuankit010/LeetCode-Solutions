class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        
        int minVal = arrays[0].front();
        int maxVal = arrays[0].back();

        for(int i = 1; i < arrays.size(); i++) {
            ans = max(ans, abs(arrays[i].back() - minVal));  // Max distance using the current array's max and previous min
            ans = max(ans, abs(maxVal - arrays[i].front()));      // Max distance using the current array's min and previous max

            minVal = min(minVal, arrays[i].front());              // Update the overall minimum value
            maxVal = max(maxVal, arrays[i].back());          // Update the overall maximum value
        }

        return ans;
    }
};
