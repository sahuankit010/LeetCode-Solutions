class Solution {
public:
    int twoSumLessThanK(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int maxSum=INT_MIN;
        
        int low = 0, high =arr.size()-1;
        
        while(low<high){
            int currSum = arr[low]+arr[high];
            // int mid =    low + (high-low)/2;
                // low + (high-low)/2;
            
            
            if(currSum<k and currSum>maxSum){
                // int temp = maxSum;
                maxSum = currSum;
            }
            
            else if(currSum<k) low++;
            
            else high--;
            
            
            
            
            
            
//             if(arr[currSum]<k and arr[currSum]>maxSum){
//                 // int temp = maxSum;
//                 maxSum = arr[currSum];
//             }
            
//             else if(arr[currSum]<k) low = currSum + 1;
            
//             else high = currSum - 1;
        }
        if(maxSum!=INT_MIN) return maxSum;
        return -1;
    }
};