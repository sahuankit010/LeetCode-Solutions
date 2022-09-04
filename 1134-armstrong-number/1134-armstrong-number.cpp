class Solution {
public:
    bool isArmstrong(int n) {
        
        int sum=0, temp = n;
        int count = 0;
        int temp2 = temp;
        
        while(temp2>0){
            temp2/=10;
            count++;
        }
        while(temp>0){
            int rem = temp%10;
            
            temp/=10;
            
            sum+=pow(rem,count);
        }
        
        return sum == n;
    }
};