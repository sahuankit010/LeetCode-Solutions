class Solution {
public:
    int reverse(int x) {
        bool isNegative = false;
        if(x == INT_MIN) return 0;
        if(x < 0) {
            isNegative = true;
            x = -x;
        }

        int sum = 0;

        while(x > 0){
            int rem = x % 10;
            // Check for overflow/underflow before multiplying by 10
            if (sum > INT_MAX/10 || (sum == INT_MAX / 10 && rem > 7)) return 0;
            if (sum < INT_MIN/10 || (sum == INT_MIN / 10 && rem < -8)) return 0;
            sum = sum * 10 + rem;

            x /= 10;
        }
        
        if(isNegative){
            return -sum;
        }
        return sum;


    }
};