class Solution {
public:
    int solve(int i, int n, int t[]){
        if(i==n) return 1;
        if(i>n) return 0;
        if(t[i]!=0) return t[i];
        t[i] = solve(i+1,n,t) + solve(i+2, n,t);
        return t[i];
    }
    int climbStairs(int n) {
        int t[n+1];
        memset(t,0,sizeof(t));
        return solve(0, n, t);
    }
};