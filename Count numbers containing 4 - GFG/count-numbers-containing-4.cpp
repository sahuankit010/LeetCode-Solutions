//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool contains4(int num){
      while(num>0){
          int rem = num%10;
          if(rem == 4) return true;
          num /= 10;
      }
      return false;
  }
    int countNumberswith4(int N) {
        // code here
        int ans = 0;
        for(int i=1; i<=N; i++){
            if(contains4(i)) ans++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countNumberswith4(N) << endl;
    }
    return 0;
}
// } Driver Code Ends