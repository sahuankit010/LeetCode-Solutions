class Solution {
    public double myPow(double x, int n) {

        if(n == 0) return 1f;

        if(n == Integer.MIN_VALUE){
            x = 1/x;
            n = Integer.MAX_VALUE;
            return myPow(x, n)*x;
        }

        if(n < 0){
            n = -n;
            x = 1/x;
            return myPow(x, n);
        }

        double result = 1;

        while(n > 0){
            if(n%2 == 1){
                result *= x;
            }

            n/=2;
            x*=x;
        }

        return result;
    }
}