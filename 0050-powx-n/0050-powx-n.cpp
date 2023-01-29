class Solution {
public:
    
    double fastPow(double x, long long N){
        if(N == 0) return 1.0;
        
        double half = fastPow(x, N/2);
        
        if(N % 2 == 0){
            return half * half;
        }else{
            return half*half*x;
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        
        if(N<0){
            N = -N;
            x = 1/x;
        }
        
//         double ans = 1.0;
        
//         for(long long i=1; i<=N; i++){
//             ans *= x;
//         }
        
        return fastPow(x, N);
    }
};