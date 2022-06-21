class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        
        
        int left = 0, right = arr.size()-1;
        int k = arr.size()-1;
        vector<int>ans(arr.size());
        
        while(left<=right){
            
            if(abs(arr[right])>abs(arr[left])){
                ans[k--]=arr[right]*arr[right];
                right--;
            } else {
                ans[k--]=arr[left]*arr[left];
                left++;
            }
        }
        
        return ans;
    }
};