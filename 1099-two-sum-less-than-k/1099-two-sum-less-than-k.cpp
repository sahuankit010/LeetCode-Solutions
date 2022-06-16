class Solution {
public:
    int twoSumLessThanK(vector<int>& arr, int k) {
        
        sort(arr.begin(),arr.end());
        int maxSum=INT_MIN;
        
        int low = 0, high =arr.size()-1;
        
        while(low<high){
            int currSum = arr[low]+arr[high];
            if(currSum<k and currSum>maxSum){
                maxSum = currSum;
            }
            else if(currSum<k) low++;
            else high--;
        }
        if(maxSum!=INT_MIN) return maxSum;
        return -1;
    }
};