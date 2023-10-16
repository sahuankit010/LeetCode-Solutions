class Solution {
public:
    int mod = 1e9 + 7;
    int f(int startPos, int endPos, int k, vector<vector<int>> &memo){
        if(k==0 && startPos == endPos) return 1;
        if(k==0 && startPos != endPos) return 0;
        if(memo[startPos+1000][k]!=-1) return memo[startPos+1000][k];
        int res = f(startPos+1, endPos, k-1, memo)%mod;
        res += f(startPos-1, endPos, k-1, memo)%mod;
        return memo[startPos+1000][k] = res%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> memo(3001, vector<int> (1001,-1));
        return f(startPos, endPos, k, memo);
    }
};