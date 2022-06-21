class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            if(arr[i]<0) arr[i]=-1*arr[i];
        }
        
        // sort(arr,arr+arr.size());
        sort(arr.begin(),arr.end());
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            ans.push_back(arr[i]*arr[i]);
        }
        
        return ans;
    }
};