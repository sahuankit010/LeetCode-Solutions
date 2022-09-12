class Solution {
public:
    int subtractProductAndSum(int n) {
        long long prod = 1;
        long long sum = 0;
        
        while(n){
            int rem = n%10;
            prod = (long long)(prod*rem);
            sum += rem;
            n/=10;
        }
        
        return prod - sum;
    }
};