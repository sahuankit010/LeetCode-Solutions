class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;

        sort(begin(arr), end(arr));
        int n = arr.size();
        int diff = arr[1] - arr[0];
        for(int i = 1; i < n-1 ; i++){
            diff = min(diff, arr[i+1] - arr[i]);
        }

        for(int i = 0; i < n-1; i++){
            vector<int> each;
            if(arr[i+1] - arr[i] == diff){
                each.push_back(arr[i]);
                each.push_back(arr[i + 1]);
            }
            if(each.size()) ans.push_back(each);
        }

        return ans;
    }
};