class Solution {
public:
    int numberOfSteps(int n) {
        int ans=0;
        while(n){
            if(n%2==0) n /= 2;
            else n -= 1;
            ans++;
        }
        return ans;
    }
};