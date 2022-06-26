// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        unordered_map<int,int> ump;
        
        for(int i=0;i<n;i++){
            ump[arr[i]]++;
        }
        int miss, repeat;
        for(int i=1;i<=n;i++){
            if(ump[i]==2) repeat = i;
            if(ump[i]==0) miss = i;
        }
        int *res = new int[2];
        res[0]=repeat;
        res[1]= miss;
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends