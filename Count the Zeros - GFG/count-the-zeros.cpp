//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countZeroes(int arr[], int n) {
        // code here
        int l = 0, r = n - 1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid] == 0 and mid == 0) return n-mid;
            if(arr[mid] == 0 && mid > 0 && arr[mid-1] == 1)
                return n-mid;
            else if(arr[mid] == 1) l = mid + 1;
            else if(arr[mid] == 0  && (mid-1) ==  0 && arr[mid - 1] == 0) return n-mid+1;
            else if(arr[mid] == 0  && mid > 0 && arr[mid - 1] == 0) r = mid - 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countZeroes(arr, n);
        cout << ans << "\n";
    }
    return 0;
}


// } Driver Code Ends