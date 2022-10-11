//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        // code here
        vector<int>ans;
        bool carry = false;
        for(int i=N-1; i>=0; i--){
            if(i==N-1){
                if(arr[i]+1==10){
                    carry=true;
                    ans.push_back(0);
                } else{
                    ans.push_back(arr[i]+1);
                }
            } else {
                if(carry){
                    if(arr[i]==9){
                        carry=true;
                        ans.push_back(0);
                    } else{
                        carry=false;
                        ans.push_back(arr[i]+1);
                    }
                }
                else{
                    carry = false;
                    ans.push_back(arr[i]);
                }
            }
        }
        if(carry){
            ans.push_back(1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends