class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        int n=arr.size();
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        for(int i=0;i<n-1;i++){
            diff = min(diff, abs(arr[i]-arr[i+1]));
        }
        for(int i=0;i<n-1;i++){
            if(abs(arr[i]-arr[i+1])==diff){
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};