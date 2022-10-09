class Solution {
public:
    int minSubArrayLen(int t, vector<int>& arr) {
        int ans = INT_MAX, i = 0, j = 0, n = arr.size(), sum = 0;
        while(j < n){
            sum += arr[j];
            while(sum >= t){
                ans = min(ans, j-i+1);
                sum -= arr[i++];
            }
            j++;
        }
        if(ans > n+1) return 0;
        return ans;
    }
};