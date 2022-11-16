class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        int n= arr.size();
        if(n<3) return false;
        
        int i=1;
        bool dec = false;
        for(; i<n; i++){
            cout<<i<<endl;
            if(arr[i]==arr[i-1]) return false;
            if(arr[i]<arr[i-1]) break;
        }
        bool inc = i>=2;
        if(i==n-1){
            dec = arr[n-1]<arr[n-2];
        }
        for(; i<n-1; i++){
            cout<<i<<endl;
            dec=true;
            if(arr[i]==arr[i+1]) return false;
            if(arr[i+1]>arr[i]) break;
        }
        return (i>=n-1) && dec && inc;
    }
};