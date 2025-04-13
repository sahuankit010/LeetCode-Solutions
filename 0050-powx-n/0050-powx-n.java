class Solution {
    public double myPow(double x, int n) {
        if(n == Integer.MIN_VALUE){
            x = 1/x;
            n = Integer.MAX_VALUE;
            return myPow(x, n) * x;
        }

        else if(n < 0){
            x = 1/x;
            n = -n;
            return myPow(x, n);
        }

        else if(n == 0) {
            return 1f;
        }

        double res = 1f;

        while(n>0){
            if(n%2==1){
                res*=x;
            }
            n/=2;
            x*=x;
        }

        return res;
    }
}