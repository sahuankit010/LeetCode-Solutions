class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int aa = arr[0];
        for(int i = 1;i<arr.size();i++){
            aa^=arr[i];
        }
        return aa;
    }
};