class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n%4==0 && n>=4){
            n=n/4;
        }
        if(n==1){
            return true;
        }else{
            return false;
        }
    }
};