class Solution {
public:
    
    bool isDividing(int num){
        int curr = num;
        while(num){
            int rem = num%10;
            if(rem==0 || curr%rem) return false;
            num/=10;
        }
        return true;
    }
    bool isSelfDividing(int num) {
        int n = num, digit;
        while (n) {
            digit = n%10;
            if (digit == 0 || num % digit) return false;
            n /= 10;
        }
        return true;
    }
//     vector<int> selfDividingNumbers(int left, int right) {
//         vector<int> ans;
        
//         for(int i=left; i<=right; i++){
//             if(isSelfDividing(i));
//                 ans.push_back(i);
//         }
        
//         return ans;
//     }
        vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        
        // Check each number in the range
        for(int i = left; i<=right; i++) {
            if (isSelfDividing(i))
                res.push_back(i);
        }
        return res;
    }
};