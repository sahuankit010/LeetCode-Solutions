class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num>0){
            int rem = num%10;
            sum+=rem;
            num/=10;
            if(num<=0 and sum<10) return sum;
            if(num<=0) {
                num=sum;
                sum=0;
            }
            // if(sum)
            
        }
        return 0;
    }
};