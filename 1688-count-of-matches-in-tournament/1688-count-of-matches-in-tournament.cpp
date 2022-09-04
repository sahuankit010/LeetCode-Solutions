class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while(n>1){
            int q = n/2;
            int r = n%q;
            n = n - q;
            ans+=q;
        }
        return ans;
    }
};