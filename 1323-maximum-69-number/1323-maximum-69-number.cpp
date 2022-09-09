class Solution {
public:
    int maximum69Number (int num) {
        vector<int>arr;
        
        int temp = num;
        
        while(num){
            arr.push_back(num%10);
            num/=10;
        }
        
        reverse(arr.begin(), arr.end());
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==6){
                arr[i]=9;
                break;
            }
        }
        
        int n = pow(10, arr.size()-1);
        
        int res=0;
        
        for(int i=0; i<arr.size(); i++){
            res += arr[i]*n;
            n/=10;
        }
        
        return res;
    }
};