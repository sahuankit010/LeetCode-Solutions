class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        double maxSum = 0;
        double avg = 0;
        for(int i = 0;i<k;i++){
            maxSum+=arr[i];
        }
        avg = maxSum/k;
        for(int i=k;i<arr.size();i++){
            maxSum-=arr[i-k];
            maxSum+=arr[i];
            avg = max(avg,maxSum/k);
        }
        
        return avg;
    }
};