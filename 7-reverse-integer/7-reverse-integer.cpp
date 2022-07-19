class Solution {
public:
    
    int reverse(int x) {

        long long num=0;
        int k = abs(x);
        while(k>0){
            int rem = k%10;
            num=num*10+rem;
            k/=10;
        }
        if(x<0) num=0-num;
        if(num>INT_MAX or num<INT_MIN) return 0;
        return num;
    }
};