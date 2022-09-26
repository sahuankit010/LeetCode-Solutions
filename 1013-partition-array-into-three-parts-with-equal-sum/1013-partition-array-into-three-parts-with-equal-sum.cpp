class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum%3!=0) return false;
        int n=arr.size();
        int sumP=0;
        int count=0;
        for(int i=0; i<n; i++){
            sumP += arr[i];
            if(sumP == sum/3) {
                sumP = 0;
                count++;
            }
        }
        return count >= 3;
    }
};