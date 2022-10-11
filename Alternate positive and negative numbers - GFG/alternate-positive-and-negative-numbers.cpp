//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    int p=0;
	    vector<int>pos,neg;
	    for(int i=0; i<n; i++){
	        if(arr[i]>=0){
	            pos.push_back(arr[i]);
	        } else{
	            neg.push_back(arr[i]);
	        }
	    }
	    int i=0, j=0, m=pos.size(), n1=neg.size();
	    while(i<m and j<n1){
	        arr[p++] = pos[i++];
	        arr[p++] = neg[j++];
	    }
	    
	    while(i<m){
	        arr[p++] = pos[i++];
	    }
	    
	    while(j<n1){
	        arr[p++] = neg[j++];
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends