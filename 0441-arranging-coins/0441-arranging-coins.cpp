class Solution {
public:
    int arrangeCoins(int n) {
        long long c=0, i=1;
        while(n){
            c += i;
            n -= i;
            if(n==0) return i;
            if(n<0) return i-1;
            i++;
        }
        return 0;
    }
};