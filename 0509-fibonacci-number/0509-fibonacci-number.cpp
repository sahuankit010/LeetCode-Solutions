class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int f[n+1];
        f[0]=0;
        f[1]=1;
        
        for(int i=2; i<=n; i++){
            f[i] = f[i-2]+f[i-1];
        }
        
        return f[n];
    }
};