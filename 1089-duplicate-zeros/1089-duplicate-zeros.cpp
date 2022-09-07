class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> vec(arr.begin(), arr.end());
        arr.clear();
        for(int i=0; i<n; i++){
            if(vec[i]!=0){
                arr.push_back(vec[i]);
            } else{
                if(arr.size()<n)
                    arr.push_back(0);
                if(arr.size()<n)
                    arr.push_back(0);
            }
            
            if(arr.size()==n) break;
        }
    }
};